// topthieves.c		by Yueh 1996/7/19
// This daemon scores thief bs level for log file

#include <daemons.h>
#define SIZE 5
mapping levels;

string *top_list;

string* sort_level(mapping lvs,string* top,string myname);

void log_player(object player)
{

	int myguild,myguild1, mylevel, myage, *savedata;
	string myname;

	if( !player ) return;
	if((string)player->query("class")!="thief") return;
	myname = (string)player->query("org_name");
	if( wizardp(player) ) return;
	if( PROMOTION_D->in_wiz_list(myname) ) return;

	myguild = (int)player->query("thief_level/backstab");
	myguild1=(int)player->query("thief_level/throw-dagger");

	mylevel = (int)player->query_level();
	myage = (int)player->query_age();
	savedata = ({ myguild, myguild1,mylevel, myage });
	
	if( !levels ) levels = ([]);

	if( !top_list ) top_list = ({});
	
	levels[myname] = savedata;

	top_list=sort_level(levels,top_list,myname);

}

string* sort_level(mapping lvs,string* top,string myname)
{
	int i,loc;
	loc = member_array( myname, top );
	if( loc==-1 ) {
			loc = sizeof(top);
			top += ({ myname });

		while( loc > 0 && (int)lvs[myname][0] >= (int)lvs[top[loc-1]][0] ) {
			top[loc] = top[loc-1];
			top[loc-1] = myname;
			loc--;
		}
	} else {
		i = loc;
		while( i > 0 && (int)lvs[myname][0] > (int)lvs[top[i-1]][0] ) {
			top[i] = top[i-1];
			top[i-1] = myname;
			i--;
		}
		i = loc;
		while( i < sizeof(top)-1 && (int)lvs[myname][0] < (int)lvs[top[i+1]][0] ) {
			top[i] = top[i+1];
			top[i+1] = myname;
			i++;
		}
	}
	return top;
}

varargs string get_list(int flag)
{
	int i,day, hour, *savedata,size_list;
	string msg;

	if( !sizeof(top_list) ) return 	"С͵���а�Ŀǰ�ǿյġ�\n";
	size_list=sizeof(top_list);
	if ((flag==1)&&(size_list>SIZE)) size_list=SIZE;
	msg = sprintf("С͵���а�ǰ %d  ��:\n",size_list);
	msg += sprintf(" ����  �������           �ȼ�          ����ʱ��           bs     throw-dagger \n");
	for(i=0; i<size_list; i++) {
		savedata = levels[top_list[i]];
		day = savedata[3]/86400;
		hour = savedata[3]%86400/3600;
		msg += 
			sprintf("  %2d. %20-s %2d %10d �� %2d Сʱ %10d%10d\n",i+1, 
			top_list[i], savedata[2], day, hour, savedata[0],savedata[1] );
	}

	return msg;
}

int clean_up()
{
                return 0;
}
