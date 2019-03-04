#include "saulin_temple.h"

inherit ROOM;

void create()
{
	::create();
	set("broken",0);
	set_short("��Ħ��ڴ�");
	set_long( @C_LONG_DESCRIPTION
�����Ǵ�Ħ��ʦ���ʮ��ĵط�����Ȼ��С����������ȴ�������µ�
ʥ�أ������ʯ�ڻ�����һƬ��Ӱ(shadow)���ഫ�Ǵ�Ħ��ʦ��Ӱ����ʮ
������ڼ�����������Ժ��������\��ɮ�˾�����ڣ�ϣ��Ҳ�ܵ�֤���̡�
C_LONG_DESCRIPTION
	);
    set("item_desc",([ "shadow" : @C_LONG
����ϸ�Ĳ鿴�����Ӱ��Ӱ�Ӻ�Ȼ�������ͬʱ������Ķ�������һ�����˵Ļ�
�� �� ���� !! ���Ǵ�Ħ .... ��Ӱ�ӣ���Ħ�Ǹ����һ���ǰ��������ڣ�����Ϊ
��Ҫ���Ҵ������ϸϳ�ȥ���������ˣ�ȴ���ҹ��������������ʯ��(wall)�ϣ���
Ŭ��������ǧ���꣬���ǳ���������ǽ�������ϰ��Ҵ���(break) ����ǽ������
��ȥ���������ǧ���磬�Ҿ͸�����һЩ�йش�Ħ�����ܡ�
C_LONG
    ]));
        set_outside("eastland");
	set( "exits", ([
		"west" : SAULIN"stone_path3",
	]) );
	reset();	
}

void init()
{
    add_action("break_wall", "break");
}

int break_wall(string arg)
{
	if( !arg || arg !="wall" )
	  if( !this_object()->query("broken") )
        return notify_fail( "Ӱ�ӹ�����Ц������ʲ�᣿��ı��Դ���\n" );
      else
        return notify_fail("����ʲ�᣿\n");
	if( !this_object()->query("broken") ) {
      tell_object(this_player(),@SHADOW_OUT
  �����һ���ʯͷ��ʯ����ȥ����¡һ�����죬ʯ���������Ӱ��ȴ������һ��
  ��ʯ�ڳ��˳������ɵ�����С������˵Ĵ󺰴�У��ҳ����� ! �ҳ�����!����Ħ 
  ! ˵ʲ��Ҫ�ɷ��Ҫ���ƶ�����ⲻ�ǳ������𣿵�������ǿ������ǿ��������
  !! ����ָ�����Ц��������׳շ��ˣ���ʲ��Ҳ��������� !!!
  �����������˴���� !! 
SHADOW_OUT
      );
      new( SAULIN_MONSTER"damo" )->move( this_object() );
      this_object()->set("broken",1);   
      this_player()->set_explore("eastland#33");
    } else
      tell_object(this_player(),@NOTHING
�����һ���ʯͷ��ʯ����ȥ����¡һ�����죬ʯ���������
��Ӱ���ƺ��������ӳ�����
NOTHING
      );
    return 1;
}

void reset()
{
    ::reset();
    set("broken",0);
}
