#include <../goomay.h>


inherit SELLER ;
inherit Mob_special;

void create()
{
	::create();
	set_level(4);
	set_name( "flower girl", "����Ů" );
        add ("id",({ "girl"}));
	set_short( "����Ů" );
	set_long(
		"����һ�������������������Ů�����������Ҫ�Ļ������������򻨣�ֻҪ\n"
		"������춻�(flower)���£����ͻ�����������������Ļ���\n"
	);
	set( "race", "elf" );
	set( "gender", "female" );
	set_inventory( ({
		({ Obj"petals", 10, 10 }),
		({ "/d/std/flowers/red_rose", 10, 10 }),
        ({ "/d/std/flowers/yellow_rose", 10, 10 }),
		({ "/d/std/flowers/tuberose", 10, 10 }),
        ({ "/d/std/flowers/pansy", 10, 10 }),
        ({ "/d/std/flowers/lili", 10, 10 }),
        ({ "/d/std/flowers/ironweed", 10, 10 }),
        ({ "/d/std/flowers/laurel", 10, 10 }),
	}) );

	set( "inquiry", ([
		"flower" : "@@show_menu"
	]) );
        set_natural_weapon( 5, 4, 9 );
        set_natural_armor( 40, 20 );
        set_c_verbs(({"%s��ָ��ץ��%s","%s�û�������%s","%s�ý�����%s"}));
        set("special_attack",(["damage_type" : "magic","main_damage" : 6,
				"random_dam" : 4 , "hit_rate" : 15]));
        set( "tactic_func", "my_tactic" );
set("c_enemy_msg",
    "����Ů�����Ļ����������������..\n\n");
set("c_room_msg","����Ů������Ƶ��û�������");
set("c_room_msg2", "��������ð����� ...\n");

}

void init()
{
	seller::init();
	mob_special::init();
}