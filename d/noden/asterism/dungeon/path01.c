// File: /d/noden/asterism/path01.c

#include "../asterism.h"

inherit ROOM;

int be_searched;
void create()
{
	::create();
	set_short("halfling tower", "�����˸����ĵ�����");
	set_long( @LONG_DESCRIPTION
LONG_DESCRIPTION
		,@C_LONG_DESCRIPTION
�����ǰ�˹���ɶ����а����˸����ĵ�����,�ѻ���һ�������Ӱ˵ķ�����,�����
���Ե�ʮ�ֻ���.
C_LONG_DESCRIPTION
	);

//	set( "light", 1 );
	set("search_desc",([
	    "here":"@@to_search_here",
	    ]));
	set( "exits", ([ 
		"up" : ASTR"tower1-1",
		]) );
	reset();
}

string to_search_here()
{
    if (be_searched==0)
       {
         be_searched=1;
         
         if(((int)this_player()->query_level()<13)||
            ((int)this_player()->query_perm_stat("kar")<random(21)))
             return "���ڷ������е����ҷ�, �����Ҳ������õĶ�����\n" ;

         add("exits",([
             "down":DUNGEON"path02",
             ]) );
         add("exit_msg",([
             "down":"$N�����˰�˹���ɶ�����ˮ��.\n",
             ]) );    

         return "����Щ�������µķ�������,�㻨��������ʱ��,�����һ����ľ����\n"
                "�ҵ�һ�����µ�ͨ��.\n";
        }
    else 
       return "��ط��Ѿ���������һ��������.\n" ;         

}

void reset()
{
    ::reset();
    be_searched=0;
    set( "exits", ([ 
		"up" : ASTR"tower1-1",
		]) );
    set( "exit_c_msg",([]) );
}

