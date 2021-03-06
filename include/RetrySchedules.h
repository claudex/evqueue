/*
 * This file is part of evQueue
 * 
 * evQueue is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * evQueue is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with evQueue. If not, see <http://www.gnu.org/licenses/>.
 * 
 * Author: Thibault Kummer <bob@coldsource.net>
 */

#ifndef _RETRYSCHEDULES_H_
#define _RETRYSCHEDULES_H_

#include <map>
#include <string>
#include <pthread.h>

class RetrySchedule;

class RetrySchedules
{
	private:
		static RetrySchedules *instance;
		
		pthread_mutex_t lock;
		
		std::map<std::string,RetrySchedule *> schedules;
	
	public:
		
		RetrySchedules();
		
		static RetrySchedules *GetInstance() { return instance; }
		
		void Reload(void);
		RetrySchedule GetRetrySchedule(const char *name);
};

#endif
