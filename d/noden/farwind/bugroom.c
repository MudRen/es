//modify by Hch..////#pragma save_binary
#include <mudlib.h>
#include <daemons.h>

inherit ROOM;

void create()
{
        ::create();
        set_short( "�������" );
        set_long(@C_LONG
��������վ��һ���������Ĵ��֮��, �㿴�����ܾ���ҫ�۵��߲�ˮ��,
��Щˮ�������Ĺ�â����Ŀѣ����, ���˼��������Լ����������ڡ�����Щ��â
ȫ������������һ��ħ������(statue)�����ϡ��ϱߵ�ˮ������ͨ��������á�
C_LONG
        );
        
        set("item_desc",([
            "statue":"@@c_bug_master",
        ]) );
        set( "light", 1 );
        set( "exits", ([
            "south" : "/d/noden/farwind/quest_room",
        ]) );
}
void init()
{
    add_action("do_ask","ask");
}

string c_bug_master()
{
   int hour;

   sscanf(WEATHER_D->query_game_time(),"%d",hour);
   if( hour >= 6 && hour < 18)
      write("\n���㿴�������ʱ, һ�����ɫ�Ĺ�â�ɵ������\n"
              "�ۼ�����һ������, ͬʱһ��ׯ�϶��ͳ���������\n"
              "��˵��:��������֮�ػ���,����,����ʲ��������?��\n" );
   else
      write("\n���㿴�������ʱ, һ����͵���ɫ��â�ɵ������\n"
              "�ۼ�����һ������, ͬʱһ�������ö�����������\n"
              "˵��:������ҹ֮�ػ���,����,����ʲ��������?��\n" );
   cat( "/d/doc/domain_master/domain_list" );
   return "�������(ask)����˭���ԡ���Ч�ء�������.\n";
}
int do_ask(string arg)
{
       mixed num;
    if( !arg ) {
        write("�����ʹ�� ask <number> ��ø��������.\n");
       return 1;
    } else if( sscanf(arg,"%d",num) == 1 ) {
        cat( "/d/doc/domain_master/bug_master_"+num );

        return 1;
    }
    write("�����ʹ�� ask <number> ��ø��������.\n");
    return 1;
}

