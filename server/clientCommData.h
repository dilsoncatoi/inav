/**
 * * INAV - Interactive Network Active-traffic Visualization
 * * Copyright © 2007  Nathan Robinson, Jeff Scaparra
 * *
 * * This file is a part of INAV.
 * *
 * * This program is free software: you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License as published by
 * * the Free Software Foundation, either version 3 of the License, or
 * * (at your option) any later version.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * */


#ifndef CLIENTCOMMDATA_H
#define CLIENTCOMMDATA_H

#include <fstream>
#include <string>
#include "baseData.h"
#include "../common/constants.h"
#include "filterData.h"
#include "graphData.h"
#include "../common/threads.h"

class ClientCommData : public BaseData
{
	public:
		ClientCommData( Mutex& coutMutex, Mutex& logMutex,
				std::ofstream *log, int serverPort = communication::ServerPort );
		int getServerPort();
		int getRefreshTime();
		void setRefreshTime( int time ); //time in sec

		//Place Holders for other data types that need trasfered to the
		//Communication Thread
		FilterData* filterData;
		GraphData* graphData;
	private:
		int serverPort_;
		int refreshTime_;
};





#endif 
