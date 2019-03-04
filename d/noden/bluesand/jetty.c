#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
   set_short("��ɳ����ͷ");
	set_long( @LONG_DESCRIPTION
��������ɳ�۵���ͷ����ģ��Ȼ���Ǻܴ󣬵���ŵ�������Ͷ������
��ó�׼�����Ҫ�����������ͷ������Կ�����ʽ�����Ĵ�ֻ(ship)��
����(boxes)������װ�Ĵ󲿷ֶ������Զ����Ļ�Ʒ��ֻ���ٲ�����ŵ����
���Ļ��
LONG_DESCRIPTION
	);

	set_outside( "noden" );
	set( "light", 1 );
	set( "c_item_desc", ([ 
		"ship" : @LONG_TEXT
��Щ��ֻ�е�˫Φ���е���Φ�����������ǽ�����ʺ�Զ�������ӣ���ע��
��һ���ð����ڴ����������������š��Ĵ�ͣ������ͷ�Ķ��߲�Զ�������
�����Ӿ(swim)��Ҳ������ι�ȥ������\n
LONG_TEXT
, 
		"boxes" : "��Щ������������ض�����ͷ�ϣ��ȴ���ͷ���˹������ˡ�\n" ]) );
    set( "exits", ([ 
		"west" : "/d/noden/bluesand/port_r2" ]) );
	set( "objects", ([
		"jeff" : "/d/noden/bluesand/monster/jeff" ]) );
	reset();
}

void init()
{
	add_action("do_swim", "swim" );
	if( !find_object("/d/std/ocean/ship_iriah") )
		"/d/std/ocean/ship_iriah"->frog();
	if( !find_object("/d/std/ocean/ship_death") )
		"/d/std/ocean/ship_death"->frog();
}

int do_swim()
{
    int swim_skill;

	swim_skill = (int)this_player()->query_skill("swimming");
	if( random(swim_skill) < 20 ) {
            write(
                    "����˼����������̵ĺ�ˮ���Ǳ������ذ��ϡ�\n" );
            tell_room( this_object(),
this_player()->query("c_cap_name")+"��������ÿ�Ц���������˼����ߣ�Ȼ���Ǳ������ذ��ϡ�\n",
			this_player() );
		return 1;
	}
   write(
"����������ĺ�ˮ�����������Ҵ���ȥ�����ץ�������Ե����������ϴ�ͷ��\n" );
    tell_room( this_object(),
          this_player()->query("c_cap_name")+"����������򶫱ߵ�һ�Ҵ��ϡ�\n",
		this_player() );
	this_player()->move_player("/d/noden/bluesand/ship", "SNEAK");
	return 1;
}

