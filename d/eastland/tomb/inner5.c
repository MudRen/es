#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("��Ĺ");
	set_long( 
@C_LONG_DESCRIPTION
������Ǵ�˵�е���Ĺ�ˣ�����ͷ���Ͼ���һƬ�貵��ǿգ����������ý�������ģ�
��һ����������һ������覵ı���������������ǿ����¡������ϱ�����������С���
������½ !! ����ɽ������ľ�����޲�ά��άФ����������������ˮ�ڻ���������������̫
�����ˣ���֪��ǰ������δ������㾰��ίʵ���˾��塣������һƬ�޴�����ɫ����
��(jade)����Լ͸������ĺ�⣬�������ʲ�ᱦ��ɡ�
C_LONG_DESCRIPTION
	);

	set( "light",1);
	set( "exits", ([ 
		"east"  : TOMB"/inner4",
		"west"  : TOMB"/inner6"  ]) );
	set( "item_desc", ([
		"jade" : "����һƬ�޴����䣬������������覵�����ɫ����֪������\n"
			 "Ʒ���ж�á���ע�⵽�Ա��л������ĺۼ���Ҳ\��\���������\n"
			 "����(push)����\n" ]) );
	reset();	
}

void init()
{
	add_action( "do_push" , "push" );
}

int do_push(string str)
{
	object who;
	who = this_player();
	
	if ( !str || str == "" ) return notify_fail("��ɶ��\n");
	if ( str == "jade" || str == "door" ) {
		if ( (int)who->query_stat("str") < 15 ) 
			return notify_fail("��ʹ�����̵������������Ʋ�������\n");
		if ( (int)who->query_stat("pie") < 15 )
			return notify_fail("������һ������˵����������������������޷������ !!\n");
		tell_object(who,
			"�������һ�ƣ��������⻬�����������һ���µ�ʯ���С�\n" );
		tell_room(this_object(),
			sprintf("%s������ƿ������˽�ȥ��������漴�ָ�ԭ״��\n",
				who->query("c_cap_name")) , who );
		tell_room(TOMB"/inner9",
			sprintf("%s������ƿ������˹�����������漴�ָ�ԭ״��\n",
				who->query("c_cap_name")) , who );
		who->move_player(TOMB"/inner9","SNEAK");
		return 1;
		}
	return notify_fail("��ɶ��\n");
}