//#pragma save_binary

// Unos translacion de Platino, Mar 4 2:33:23 1994

#include <mudlib.h>

inherit ROOM;

int beehive = 0;

void create()
{
	::create();
    set_short( "������");
	set_long( @C_LONG_DESCRIPTION
������׾ٵر�������������������������¿����Կ���Զ���������
���Աߵ�һ���ɫС�ݣ���....��....��������һ���߲����ĵط���һ����
�ϴ�ķ���(beehive) ���۷����˵������ƺ�������Ķ��ߣ����ǸϽ��뿪
����ط����⾪�����ǡ�
C_LONG_DESCRIPTION
	);

	set( "exits", ([
		"down" : "/d/noden/farwind/w_gate"
	]) );
	set( "objects", ([
		"witch" : "/d/noden/farwind/monster/witch" ]) );
	set( "item_desc", ([
        "beehive" :
			"һ�������ϲ���ķ��ѣ�����ò�Ҫ��̫���������۷��ܵ����š�\n",
	]) );
    reset();
}

void init()
{
	add_action( "do_hit", "hit" );
	if( this_player() ) this_player()->set_explore("noden#0");
}

int do_hit(string arg)
{
	object obj;
	int i;

	if( !arg || arg!="beehive" ) return 0;
	write( "��������ŵؿ������ѣ�����������һ�ã�\n");
	tell_room( this_object(), 
		this_player()->query("c_name") + "������ŵؿ������ѣ�Ȼ������������һ�ã�\n",
		this_player() );
	if( beehive ) return 1;
	beehive = 1;
	for( i=0; i<6; i++ ) {
		obj = new( "/d/noden/monster/hornet" );
		obj->move(this_object());
	}
	for( i=0; i<3; i++ ) {
		obj = new( "/d/noden/monster/hornet_soldier" );
		obj->move(this_object());
	}
	
	this_player()->set_explore( "noden#3" );
	
	this_player()->gain_experience(100);
	write( "��õ� 100 �㾭�顣\n" );
	return 1;
}
