#include <../zeus.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(17);
	set_name("paradise guard", "������ʿ");
	add( "id", ({ "guard" }) );
	set_short("�ƾ�����");
	set_long(@AA
��������Ƕμ��صشӾ��˹�����������ʿ����Ȼ��������\��\���Ƕ����
�����ҳϵ�����ȴ�����˿ɱȵģ������۹�����ض������ţ������κ�һ
����͵͵���ȥ��
AA
);
	set_perm_stat("str", 27);
	set_perm_stat("int", 20);
	set_perm_stat("dex", 22);
	set_perm_stat("kar", 20);
	set_skill("blunt", 100);
	set_skill("parry", 100);
	set( "hit_points", 500 );
	set( "max_hp", 500 );
	set( "alignment", 100 );

	set( "gender", "male" );
	set( "race", "troll" );
	set_natural_armor( 50, 20 );
	set_natural_weapon( 20, 10, 20 );
	set( "class", "knight" );
	set( "special_defense", ([ "all": 25 ]) );

	wield_weapon( ZOBJ"/black_staff" );

	equip_armor( ZOBJ"/black_plate" );
	equip_armor( ZOBJ"/black_leggings" );
}
void die()
{   object obj,who;
    tell_room(environment(this_object()),
@DIE

�㷢��������ʿ���������е�һ��Կ�ף����˳�����

DIE
,this_object());
   ::die(1);
   obj=new(ZOBJ"/wine_key");
    obj->move(this_object());
   }