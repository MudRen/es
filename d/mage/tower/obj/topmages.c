// topmages.c		by Yueh 1995/3/11
// This daemon scores mage's magic levels and make a top 5 list.

#define SIZE 5

#include <daemons.h>

mapping levels0;
mapping levels;
mapping levels1;
mapping levels2;
mapping levels3;

string *top_list0;
string *top_list;
string *top_list1;
string *top_list2;
string *top_list3;
string* sort_level(mapping lvs,string* top,string myname,int check);

void log_player(object player)
{

	int myguild, mylevel, myage, *savedata,*savedata1,*savedata2,*savedata3;
	int myguild1,myguild2,myguild3,*savedata0;
	string myname;

	if( !player ) return;
	if((string)player->query("class")!="mage") return;
	myname = (string)player->query("name");
	if( wizardp(player) ) return;
	if( PROMOTION_D->in_wiz_list(myname) ) return;

	myguild = (int)player->query("spell_levels/guild");
	myguild1=(int)player->query("spell_levels/elemental");
	myguild2=(int)player->query("spell_levels/black-magic");
	myguild3=(int)player->query("spell_levels/misc");

	mylevel = (int)player->query_level();
	myage = (int)player->query_age();
	savedata0 = ({ myguild, myguild1,myguild2,myguild3,mylevel, myage });
	savedata = ({ myguild, mylevel, myage });
	savedata1 = ({ myguild1, mylevel, myage });
	savedata2 = ({ myguild2, mylevel, myage });
	savedata3 = ({ myguild3, mylevel, myage });
	
	if( !levels0 ) levels0 = ([]);
	if( !levels ) levels = ([]);
	if( !levels1 ) levels1 = ([]);
	if( !levels2 ) levels2 = ([]);
	if( !levels3 ) levels3 = ([]);

	if( !top_list0 ) top_list0 = ({});
	if( !top_list ) top_list = ({});
	if( !top_list1 ) top_list1 = ({});
	if( !top_list2 ) top_list2 = ({});
	if( !top_list3 ) top_list3 = ({});
	
	levels0[myname] = savedata0;
	levels[myname] = savedata;
	levels1[myname] = savedata1;
	levels2[myname] = savedata2;
	levels3[myname] = savedata3;

	top_list0=sort_level(levels0,top_list0,myname,1);
	top_list=sort_level(levels,top_list,myname,0);
	top_list1=sort_level(levels1,top_list1,myname,0);
	top_list2=sort_level(levels2,top_list2,myname,0);
	top_list3=sort_level(levels3,top_list3,myname,0);
}

string* sort_level(mapping lvs,string* top,string myname,int check)
{
	int i,loc;
	loc = member_array( myname, top );
	if( loc==-1 ) {
		if (check ==0){
			if( sizeof(top) < SIZE ) {
				loc = sizeof(top);
				top += ({ myname });
			}
			else loc = SIZE;
		} else
		{
			loc = sizeof(top);
			top += ({ myname });
		}

		while( loc > 0 && (int)lvs[myname][0] >= (int)lvs[top[loc-1]][0] ) {
			if ((check==1)||( loc < SIZE )) 
			top[loc] = top[loc-1];
			top[loc-1] = myname;
			loc--;
		}
	} else {
		i = loc;
		while( i > 0 && (int)lvs[myname][0] > (int)lvs[top[i-1]][0] ) {
			if ((check==1)||( loc < SIZE )) 
			top[i] = top[i-1];
			top[i-1] = myname;
			i--;
		}
		i = loc;
		while( i < sizeof(top)-1 && (int)lvs[myname][0] < (int)lvs[top[i+1]][0] ) {
			if ( (check==1)||(loc < SIZE) ) 
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

	if( !sizeof(top_list) ) return 	"魔法等级排行榜目前是空的。\n";
	if (flag==0){
	size_list=sizeof(top_list0);
	msg = sprintf("魔法等级排行榜前 %d名:\n", size_list) ;
	msg += sprintf(" 名次  玩家姓名      等级     上线时间        综合   元素    黑    杂项\n");
	for(i=0; i<size_list; i++) {
		savedata = levels0[top_list0[i]];
		day = savedata[5]/86400;
		hour = savedata[5]%86400/3600;
		msg += 
			sprintf("  %2d. %15-s %2d %6d 天 %2d 小时 %6d %6d %6d %6d\n",i+1, 
			top_list0[i], savedata[4], day, hour, savedata[0], savedata[1],savedata[2],savedata[3]);
	}
	return msg;
	}

	size_list=sizeof(top_list);
	if (size_list>SIZE) size_list=SIZE;
	msg = "综合魔法等级排行榜前 " + size_list + " 名:\n";
	msg += sprintf(" 名次  玩家姓名           等级          上线时间                    魔法等级\n");
	for(i=0; i<size_list; i++) {
		savedata = levels[top_list[i]];
		day = savedata[2]/86400;
		hour = savedata[2]%86400/3600;
		msg += 
			sprintf("  %2d. %20-s %2d %10d 天 %2d 小时 %20d\n",i+1, 
			top_list[i], savedata[1], day, hour, savedata[0] );
	}
	msg += "\n元素魔法等级排行榜前 " + size_list + " 名:\n";
	msg += sprintf(" 名次  玩家姓名           等级          上线时间                    魔法等级\n");
	for(i=0; i<size_list; i++) {
		savedata = levels1[top_list1[i]];
		day = savedata[2]/86400;
		hour = savedata[2]%86400/3600;
		msg += 
			sprintf("  %2d. %20-s %2d %10d 天 %2d 小时 %20d\n",i+1, 
			top_list1[i], savedata[1], day, hour, savedata[0] );
	}
	msg += "\n黑魔法等级排行榜前 " + size_list + " 名:\n";
	msg += sprintf(" 名次  玩家姓名           等级          上线时间                    魔法等级\n");
	for(i=0; i<size_list; i++) {
		savedata = levels2[top_list2[i]];
		day = savedata[2]/86400;
		hour = savedata[2]%86400/3600;
		msg += 
			sprintf("  %2d. %20-s %2d %10d 天 %2d 小时 %20d\n",i+1, 
			top_list2[i], savedata[1], day, hour, savedata[0] );
	}
	msg += "\n杂项魔法等级排行榜前 " + size_list + " 名:\n";
	msg += sprintf(" 名次  玩家姓名           等级          上线时间                    魔法等级\n");
	for(i=0; i<size_list; i++) {
		savedata = levels3[top_list3[i]];
		day = savedata[2]/86400;
		hour = savedata[2]%86400/3600;
		msg += 
			sprintf("  %2d. %20-s %2d %10d 天 %2d 小时 %20d\n",i+1, 
			top_list3[i], savedata[1], day, hour, savedata[0] );
	}

	return msg;
}

int clean_up()
{
                return 0;
}
