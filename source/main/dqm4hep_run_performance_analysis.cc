  /// \file dqm4hep_run_performance_analysis.cc
/*
 *
 * dqm4hep_run_performance_analysis.cc main source file template automatically generated
 * Creation date : mer. nov. 5 2014
 *
 * This file is part of DQM4HEP libraries.
 *
 * DQM4HEP is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * based upon these libraries are permitted. Any copy of these libraries
 * must include this copyright notice.
 *
 * DQM4HEP is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with DQM4HEP.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @author Remi Ete
 * @copyright CNRS , IPNL
 */

// -- dqm4hep headers
#include "dqm4hep/DQM4HEP.h"
#include "dqm4hep/DQMLogging.h"
#include "dqm4hep/DQMPerformance.h"

// -- tclap headers
#include "tclap/CmdLine.h"
#include "tclap/Arg.h"

// -- std headers
#include <iostream>
#include <signal.h>

#include "TCanvas.h"
#include "TApplication.h"
#include "TFile.h"

using namespace std;
using namespace dqm4hep;

bool runPerformanceManager = true;
TApplication *pApplication = NULL;

// key interrupt signal handling
void stop_performance_client(int signal)
{
	runPerformanceManager = false;

	if(pApplication)
		pApplication->Terminate(0);
}


int main(int argc, char* argv[])
{
	DQM4HEP::screenSplash();

	std::string cmdLineFooter = "Please report bug to <rete@ipnl.in2p3.fr>";
	TCLAP::CmdLine *pCommandLine = new TCLAP::CmdLine(cmdLineFooter, ' ', DQM4HEP_VERSION_STR);

	TCLAP::ValueArg<std::string> saveRootFileNameArg(
				  "f"
				 , "root-file"
				 , "The root file to save performance histograms"
				 , false
				 , ""
				 , "string");
	pCommandLine->add(saveRootFileNameArg);

	pCommandLine->parse(argc, argv);

	// install signal handlers
	std::cout << "Installing signal handlers ... " << std::endl;
	signal(SIGINT,  stop_performance_client);

	streamlog_out(MESSAGE) << "Creating application ... " << std::endl;

	DQMPerformanceManager *pPerformanceMgr = new DQMPerformanceManager();

	std::cout << "Press CTRL + C to stop received performance contents and draw performance plots ... " << std::endl;

	while(runPerformanceManager)
	{
		pPerformanceMgr->printStats();
		sleep(1);
	}

	// stop dim infos
	pPerformanceMgr->clear();

	// get the histogram map of the accumulated received performances
	std::map<std::string, TH1F *> histogramMap = pPerformanceMgr->createHistograms();

	if(histogramMap.empty())
		return 0;

	std::vector<TObject *> deleteList;
	pApplication = new TApplication("DQM4HEP Performance Analysis", &argc, argv);

	for(std::map<std::string, TH1F *>::iterator iter = histogramMap.begin(), endIter = histogramMap.end() ;
			endIter != iter ; ++iter)
	{
		TCanvas *pCanvas = new TCanvas(iter->first.c_str(), iter->first.c_str());
		pCanvas->cd();

		iter->second->Draw();

		deleteList.push_back(iter->second);
		deleteList.push_back(pCanvas);
	}

	if(saveRootFileNameArg.isSet())
	{
		std::string rootFileName = saveRootFileNameArg.getValue();
		TFile *pFile = TFile::Open(rootFileName.c_str(), "RECREATE");

		if(pFile)
		{
			for(std::map<std::string, TH1F *>::iterator iter = histogramMap.begin(), endIter = histogramMap.end() ;
					endIter != iter ; ++iter)
			{
				iter->second->SetDirectory(pFile);
				iter->second->Write();

				// set directory to 0, avoiding deletion of histo while deleting file
				iter->second->SetDirectory(0);
			}

			pFile->Close();
			delete pFile;
		}
	}

	pApplication->Run();

	return 0;
}
