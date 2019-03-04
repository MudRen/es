#include "ruin.h"
inherit ROOM;

void create()
{
	::create();
	set("light",0);
	set_short("ͨ��");
	set_long(@CLong
���������ϱ������ͨ��, �������ҵ�ǽ�ھ�����ʯ�����ɵ�, ����
�൱����ΰ׳�ۡ�ͨ��������������������ʯ����, ���Ҹ������в�ͬ��
��������, ����Ϊ�����ߵ���˼��̾���ѡ�
    ������������������һƬ�ڰ���
CLong
	);
	set("exits",([
		"south"	: RUIN"tunnel_2",
		"north"	: RUIN"tunnel_4",
		]));

        add( "item_desc", ([
                "statues"       : @C_ITEM_DESC_1
    ��Щʯ���񶼱�����춱���һ��������İ�Բ��С����, ��ά������
���á����ǵľ�����С����������������, ���õ�������������������
̬�����ǳ���Ȥ�����䵱����һֻ������ģ����С������ǿɰ����ˡ�
C_ITEM_DESC_1
                ,"statue"       : @C_ITEM_DESC_2
    ����������һֻ��Ƥ��С��, ����С��, ���������۾�������,
�����̲�ס�����������������
C_ITEM_DESC_2
                ]) );

	reset();
}

void init()
{
	add_action("do_touch_statue", "touch");
}

int is_a_user(object player)
{
	if( userp(player) ) return 1;
	return 0;
}

int do_touch_statue(string s)
{
	int i;
	object *players, me;
	
	if(!s) return notify_fail( "��Ҫ��ʲ��?\n" );
	if( (s != "hand") && (s != "statue") )
		return notify_fail( "���������ֶ�����?\n" );
	me = this_player();
	tell_room( environment(me),
		me->query("c_name") + 
		"�������������, ͻȻ���ϳ���һ����, �������ȥ!!\n"
		,me
	);
	write(@ALONG
���������������, �����ú���Ȥʱ, ͻȻ����С�����Ǿ�¶����Ц! 
��е�: ����!!�������ʱ....
ͻȻ�ŵ�һ��, ���ϳ���һ����, �������ȥ!!
ALONG
	);
   me->set_explore("noden#17");
	players = filter_array(
		all_inventory(this_object()),"is_a_user", this_object());
	for( i=0; i<sizeof(players); i++ ) {
		players[i]->move_player(RUIN"mob_storage","SNEAK");
		tell_room(environment(players[i]),
			players[i]->query("c_name")+"����������\n", players[i]
		);
	}	
	return 1;
}
