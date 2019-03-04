//#pragma save_binary

#include <mudlib.h>
inherit GUILD;

void create()
{
	object guild_master;

	::create();
	set_short("������");
	set_long(@LONG
����������һ����ΰ�Ĵ�����������������һ�����ң������ƽ�����
�ľ������������ϣ������������������ϵ�һ�����ʹŽ����������ıڹ�
���˸�ʽ�����Ľ�������ӻ�ɷ����Ȼ��������У�������ɱ֮��ȴ��
�����֡���̧ͷ�������ң���ͷ�����ĸ����֡���������������������ǽ
��Ƕ��һ���׺����(plate)���������ط�����͹�ԡ�
LONG
	);

	set("c_item_desc", ([
		"plate"	: @LONG
������������������������������������������������������������
�׺���ʯ���Ͽ��� :

	������������� 		�������²���Υ

	�᷸��׷���书		��Υ�������Բ�

	һ����ʦ���棬��ɱͬ�š�
	
	����ύ��а������ΪŰ��
	
	������٬���ˣ�̰ɫ�ɻ���
	
�����Ź棬�������Ž����ķ������������ߣ����� help swordman
���˽Ȿ�ɡ�
������������������������������������������������������������
LONG
	]) );

	set("exits", ([
		"down" : "/u/r/ruby/rooms/workroom",
	]) );

	set ("light", 1);
	guild_master = new("/d/swordman/guild/monsters/master");
	guild_master->move( this_object() );

	set( "pre_exit_func", ([
		"east" : "check_swordman" ]) );
	set( "no_monster", 1 );

	call_other("/d/swordman/guild/swordman_board", "???");

	set_guild( "swordman" );
	reset();
}

int clean_up() { return 0; }

int check_swordman()
{
	if( wizardp(this_player()) ) return 0;
	if( (string)this_player()->query("class")!="swordman" ) {
		write("�Բ���ֻ�б���ͬ�Ų��ܽ�ȥ��\n" );
		return 1;
	}
	return 0;
}

