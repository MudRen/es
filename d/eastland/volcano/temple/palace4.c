#include <daemons.h>
#include "../oldcat.h"

inherit "/d/eastland/volcano/temple/in_well";

int min,hour,day,year;
string month;

void create()
{
	::create();
	set_short( "����" );
	set_long(
@LONG
���������ھ����������ȣ�һյյ�����ƻ��������ȵ����ԣ�����������ʲ����
�����ر�С�ģ�����ᷢ��ʲ����ֻ����֪����
��ע�⵽�����������һ�Ⱥ챦ʯ����(door)��
LONG
	);
	set( "exits", ([
             "north" : OTEMP"palace6",
             "west" : OTEMP"palace4",
	     "east" : OTEMP"palace3",
	]) );
        set("item_desc",([
            "door":
"һ�Ⱥ챦ʯ���ţ��������п�Բ��ˮ��(crystal)����������ű��迴׼ʱ�䡣\n",
            "crystal":"@@look_crystal",
            ]) );
         set("pre_exit_func",([
             "west":"to_west"
             ]) );
         set("light",1);
         reset(); 
}

int to_west()
{
  printf("\n���ϵ�ˮ������һ���������������壬������ű��ƿ���\n");
  return 0;
}

string look_crystal()
{
  string str;

  sscanf(WEATHER_D->query_game_time(),"%d:%d, %s %d, Year %d",hour,min,month,day,year);
//  printf("%d %d\n",hour,min);
  if ((((min-30)>hour) && (hour<12)) || (((min-15)>hour) && (hour>12)) )
    this_player()->set_temp("ruby_door",1);
  else
    this_player()->delete_temp("ruby_door");
  str="\n����ˮ����ȥ������Ĵ����濴��һ���� �� \n"+ WEATHER_D->query_c_game_time()+"\n\n";
  return str;
}

void init()
{
  add_action("do_touch","touch");
}

int do_touch(string arg)
{
  if (!arg || arg!="crystal" )
    return 1;
  if (this_player()->query_temp("ruby_door")) {
    printf("\nˮ������һ����͵İ׹⽫�����֣�\n");
    printf("\n�㶨�������������Լ������ܴ��۵���������Χ��\n");
    this_player()->move_player(OTEMP"palace9","SNEAK");
    this_player()->delete_temp("ruby_door");
    return 1; }
  printf("\nˮ���������죺�����ò���ʱ��\n");
  return 1;
}
