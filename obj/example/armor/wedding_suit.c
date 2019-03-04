// chainmail.c
// A standard piece of armor, heavily commented to explain what all the
// properties are.
// Created by Mobydick@TMI-2, 9-30-92

#include <mudlib.h>

inherit ARMOR ;

void create()
{
	set_name( "wedding suit", "�������");
	add( "id", ({ "suit", "wedding suit" }) );
	set_short( "a white wedding suit", "��ɫ�������");
	set_long(
		"This is a white, beautiful wedding suit.\n",
		"����һ������ɫ�Ľ�����, �ڻ���ʱ���ﴩ�������ܴ�ҵ�ף����\n" +
		"����������ʽ��������������岻֪�������Ů�������ѡ�\n"
	);
	set( "type", "body" );
	set( "armor_class", 20 );
	set( "defense_bonus", 15 );
	set( "weight", 10 );
	set( "value", ({ 100, "gold" }) );
	set( "unit", "��" );
}

void init()
{
	add_action("do_wear", "wear");
}

int do_wear(string str)
{
	if ( (string)this_player()->query("gender") != "female") {
	printf( can_read_chinese() ? 
				"����Ц��, ���뵱������?\n" :
				"You are sure kidding!\n");
	return 1;
	}
}
		
