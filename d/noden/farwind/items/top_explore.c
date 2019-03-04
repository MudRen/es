// This daemon scores player's explored points.
// by Elsa ... update at Jun 15 1995

#define SIZE 5

#include <daemons.h>

mapping points;
mapping points1;
mapping points2;
mapping points3;

string *top_list;
string *top_list1;
string *top_list2;
string *top_list3;
string *sort_explore_points(mapping points,string* top,string name);

void log_player(object player)
{	int noden,eastland,deathland,average;
	int *savedata,*savedata1,*savedata2,*savedata3;
	int level,age;
	string name;

	if( !player ) return;
	if( wizardp(player) ) return;
	name = (string)player->query("name");
	if( PROMOTION_D->in_wiz_list(name) ) return;

	level=(int)player->query_level();
	age  =(int)player->query_age();

	noden    =(int)player->query_explore_points("noden");
	eastland =(int)player->query_explore_points("eastland");
	deathland=(int)player->query_explore_points("deathland");
	average  =(int)player->query_explore_points();
	
	savedata  = ({ noden    , level, age });
	savedata1 = ({ eastland , level, age });
	savedata2 = ({ deathland, level, age });
	savedata3 = ({ average  , level, age });
	
	if( !points  ) points  = ([]);
	if( !points1 ) points1 = ([]);
	if( !points2 ) points2 = ([]);
	if( !points3 ) points3 = ([]);

	if( !top_list  ) top_list  = ({});
	if( !top_list1 ) top_list1 = ({});
	if( !top_list2 ) top_list2 = ({});
	if( !top_list3 ) top_list3 = ({});
	
	points [name] = savedata;
	points1[name] = savedata1;
	points2[name] = savedata2;
	points3[name] = savedata3;

	top_list =sort_explore_points(points ,top_list ,name);
	top_list1=sort_explore_points(points1,top_list1,name);
	top_list2=sort_explore_points(points2,top_list2,name);
	top_list3=sort_explore_points(points3,top_list3,name);
}

string* sort_explore_points(mapping points,string* top,string name)
{	int i,loc;

	loc = member_array( name, top );
	if( loc==-1 ) {
		if( sizeof(top) < SIZE ) {
			loc = sizeof(top);
			top += ({ name });
		}
		else loc = SIZE;
		while( loc > 0 && (int)points[name][0] >= (int)points[top[loc-1]][0] ) {
			if( loc < SIZE ) top[loc] = top[loc-1];
			top[loc-1] = name;
			loc--;
		}
	} else {
		i = loc;
		while( i > 0 && (int)points[name][0] > (int)points[top[i-1]][0] ) {
			if( loc < SIZE ) top[i] = top[i-1];
			top[i-1] = name;
			i--;
		}
		i = loc;
		while( i < sizeof(top)-1 && (int)points[name][0] < (int)points[top[i+1]][0] ) {
			if( loc < SIZE ) top[i] = top[i+1];
			top[i+1] = name;
			i++;
		}
	}
	return top;
}

varargs string get_list()
{	int *savedata,day,hour;
	string msg;
	int i,j,percentage,remainder,total_points;

	if( !sizeof(top_list) ) return "̽�ն����а�Ŀǰ�ǿյġ�\n";
	
	total_points=EXPLORE_D->query_total_explore("noden");
	if (total_points < 1) return "Abort program !!(ϵͳ��δ�趨�κ�̽�նȻ�������������)\n";
	msg ="\nŵ�ٴ�½̽�ն����а�ǰ " + sizeof(top_list) + " ��:\n";
	msg += sprintf(" ����  �������           �ȼ�          ����ʱ��               ̽�ն�\n");
	for(i=0; i<sizeof(top_list); i++) {
		savedata = points[top_list[i]];
		day = savedata[2]/86400;
		hour = savedata[2]%86400/3600;
		percentage=savedata[0]*10000/total_points;
		remainder=percentage%100;
		if (percentage > 10000) percentage=10000;
		msg += sprintf("  %2d. %20-s %2d %10d �� %2d Сʱ %13d.%1d%1d%%\n",i+1,
			top_list[i],savedata[1],day,hour,percentage/100,remainder/10,remainder%10 );
	}
	
	total_points=EXPLORE_D->query_total_explore("eastland");
	if (total_points < 1) return "Abort program !!(ϵͳ��δ�趨�κ�̽�նȻ�������������)\n";
	msg += "\n������½̽�ն����а�ǰ " + sizeof(top_list1) + " ��:\n";
	msg += sprintf(" ����  �������           �ȼ�          ����ʱ��               ̽�ն�\n");
	for(i=0; i<sizeof(top_list1); i++) {
		savedata = points1[top_list1[i]];
		day = savedata[2]/86400;
		hour = savedata[2]%86400/3600;
		percentage=savedata[0]*10000/total_points;
		remainder=percentage%100;
		if (percentage > 10000) percentage=10000;
		msg += sprintf("  %2d. %20-s %2d %10d �� %2d Сʱ %13d.%1d%1d%%\n",i+1,
			top_list1[i],savedata[1],day,hour,percentage/100,remainder/10,remainder%10 );
	}
	
	total_points=EXPLORE_D->query_total_explore("deathland");
	if (total_points < 1) return "Abort program !!(ϵͳ��δ�趨�κ�̽�նȻ�������������)\n";
	msg += "\n������½̽�ն����а�ǰ " + sizeof(top_list2) + " ��:\n";
	msg += sprintf(" ����  �������           �ȼ�          ����ʱ��               ̽�ն�\n");
	for(i=0; i<sizeof(top_list2); i++) {
		savedata = points2[top_list2[i]];
		day = savedata[2]/86400;
		hour = savedata[2]%86400/3600;
		percentage=savedata[0]*10000/total_points;
		remainder=percentage%100;
		if (percentage > 10000) percentage=10000;
		msg += sprintf("  %2d. %20-s %2d %10d �� %2d Сʱ %13d.%1d%1d%%\n",i+1, 
			top_list2[i],savedata[1],day,hour,percentage/100,remainder/10,remainder%10 );
	}

	total_points=EXPLORE_D->query_total_explore();
	if (total_points < 1) return "Abort program !!(ϵͳ��δ�趨�κ�̽�նȻ�������������)\n";
	msg += "\nƽ��̽�ն����а�ǰ " + sizeof(top_list3) + " ��:\n";
	msg += sprintf(" ����  �������           �ȼ�          ����ʱ��               ̽�ն�\n");
	for(i=0; i<sizeof(top_list3); i++) {
		savedata = points3[top_list3[i]];
		day = savedata[2]/86400;
		hour = savedata[2]%86400/3600;
		percentage=savedata[0]*10000/total_points;
		remainder=percentage%100;
		if (percentage > 10000) percentage=10000;
		msg += sprintf("  %2d. %20-s %2d %10d �� %2d Сʱ %13d.%1d%1d%%\n",i+1,
			top_list3[i], savedata[1], day, hour,percentage/100,remainder/10,remainder%10 );
	}

	return msg;
}

int clean_up()
{
	return 0;
}
