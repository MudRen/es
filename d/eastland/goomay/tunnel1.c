#include "goomay.h"

inherit ROOM;

void create()
{
        ::create() ;
        set_short("�ص�" );
        set_long(
@LONG
����һ��խխ�ĵص�������������ֻ������ǿ������ǰ��������
�ص���֪���ж೤��Ҳ��֪����һ����ͨ�����
LONG
        );
        
        reset();
}

void init()
{
    add_action("to_climb", "climb");
}
int to_climb( string arg )
{
    if( !arg || (arg != "backward" && arg !="forward") )
      return notify_fail("Climb backward or forward ?\n");
    if( arg=="forward" )
	{
	if (random(6)==3 )
		{
        write(
          "��Ŭ������ǰ������춵��˶��ڵ�һ�ˣ����ǳ����Ѿ���һ���������ס�� !!\n");
      this_player()->move_player( Goomay"tunnel2", "SNEAK" );
        tell_room( Goomay"tunnel2", 
         this_player()->query("c_name") + "��һ��ҳ�֮�дӵص��Ƕ���������\n"
        ,this_player() );

			return 1;
		}
	else
		{
        write(
          "��Ŭ������ǰ����ֻ��ǰ�滹�Ǻ������һƬ����֪�����ж��\n");
			return 1;
		}
	}
        write( 
          "������˳��ص���һ·���������ص���\n");
      this_player()->move_player( Goomay"jail_room2", "SNEAK" );
        tell_room( Goomay"jail_room2", 
         this_player()->query("c_name") + "��һ��ҳ�֮�дӵض������˳�����\n"
        ,this_player() );

    return 1;
}
