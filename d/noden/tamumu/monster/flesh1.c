#include "/d/noden/nodania/nodania.h"
inherit "/d/noden/tamumu/monster/guard.c";
void create()
{
	::create();
	set_level(5);
	set_name( "flesheater", "��ʳ��" );
	set_short( "��ʳ��" );
	set( "post_name","'s flesheater" );
	set( "c_post_name","ѱ������ʳ��" );
	set_long(
		"��ʳ��....\n"
	);
	setenv( "C_MMIN","$N���˹�����");
	setenv( "C_MMOUT","$N���������뿪��");
	
	set( "gender", "male" );
	set( "war_score", 1 );
}

void init()
{
	add_action("do_send","send");
}

int do_send(string s)
{
	if (!s || s != "flesheater back")
		return 0;
	if (this_player()->query_temp("control_flesh") != 2)
		return 0;
	tell_object(this_player(),@LONG
��ʳ��֪���㲻����Ҫ���ˣ����ʼ�ͻؼ�ȥ�ˡ�
LONG
	);
	this_player()->delete_temp("now_guard");
	this_object()->remove();
	return 1;
}
