#include "goomay.h"

inherit ROOM;
int blocked;
void create()
{
        ::create() ;
	blocked=1;
        set_short( "�ص�" );
        set_long(
@LONG
����һ��խխ�ĵص�������������ֻ������ǿ������ǰ����������
�ƺ��Ѿ����������ص��ľ�ͷ�ˣ���Ϊǰ�汻��������ɳʯͷ�����ˡ�
LONG
        );
	set("dig",1);
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
    if( arg=="forward" && !blocked)
	{
	if (blocked)
	{
	write(
		   "ǰ�汻��ס�ˣ��޷�����ǰ����\n");
		return 1;
	}
	if (random(5)==3 )
		{
        write(
          "��Ŭ������ǰ������춿���һ����⣬��Ͽ����������˳�ȥ !!\n");
      this_player()->move_player( Goomay"house_brush", "SNEAK" );
        tell_room( Goomay"house_brush", 
         this_player()->query("c_name") + "��һ��ҳ�֮�дӵص����˳�����\n"
        ,this_player() );

			return 1;
		}
	else
		{
        write( can_read_chinese() ?
          "��Ŭ������ǰ����ֻ��ǰ�滹�Ǻ������һƬ����֪�����ж��\n":
          "You climb forward but just see the darkness before you ! \n" );
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
void to_find_dig(string arg)
{
        object obj;

        if( !arg || (arg!="tunnel" && arg!="here" )) {
          write("����û����Ҫ�ڵ� ! \n");
          return;
	}
	if (!blocked)
	{
        write(
                   "�ص��Ѿ���ͨ�ˣ����ּ����ڣ���ѵص��ڿ�һ�㡣\n");
		return ;
	}
	if (random(6)==3 )
                {
        write( 
          "���ò���Ŭ���������ס��ɰʯ���۵�����󺹣�����ͻȻ����¡��һ����¶��һ��ȱ�� !!\n");
		blocked=0;
        set_long(
"����һ��խխ�ĵص�������������ֻ������ǿ������ǰ��������\n"+
"����ס�Ĳ��������ƺ��Ѿ�����ͨ����Ϊ��о�ǰ����������΢�紵\n"+
"����\n");

                        return ;
}
        else
                {
	if (random(8)==2) {
        write(
          "���ò���Ŭ���������ס��ɰʯ��ͻȻ�������ͣ����ġ���һ�������Ӷ��� !!��\n");
        if (obj = present ("shovel",this_player()))
          obj->remove();

                        return ;
	}
        write(
          "���ò���Ŭ���������ס��ɰʯ���۵�����󺹣�����û�ܴ�ͨ��\n");
                        return ;
		}
}

void reset()
{
    ::reset();
    set( "blocked",1);
    blocked = 1;
}
