#include "../takeda.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(18);
    set_name("Li Kui ","����");
    add("id",({"li","kui"}) );
    set_short("����");
	set_long(@C_LONG
��ź����磬������ˮ���ˣ�һ��������⣬��ǰһƬ��ë����ɽ�ú�Ҫ�������
ɱ�ˣ���Ϊ��³��ʹһ�����ɱ����ĿǰΪ��ɽ������ͳ��֮һ��
C_LONG
	);
    set("alignment",-1000);
    set( "gender", "male" );
    set( "race", "lizardman");
    set( "unit", "��" );
    set_perm_stat( "dex",20);
    set_perm_stat( "str",30);
    set_perm_stat( "int",10);
    set_perm_stat( "karma",30);
    set_skill("axe",90);	
    set_skill("parry",90);
    set ("chat_chance",20);
    set ( "att_chat_output",({
    "���ӽе�: ɱɱɱɱɱɱɱ........\n"
        }));
    set ("max_hp",660);
    set ("hit_points",660);
    set ("time_to_heal",2);
    set ("wealth", ([ "gold":300]) );
    set_natural_weapon(28,18,33);
	set_natural_armor(50,26);
	set ("aim_difficulty",([ "weakest":40,"vascular":50]) );
	set("special_defense", (["magic":40,"none":20]) );
    set ("weight", 400);
    wield_weapon(TWEAPON"flower_axe");
    equip_armor(TARMOR"buddha_hood");
    equip_armor(TARMOR"fur_armband");
    equip_armor(TARMOR"cowskin_boots");
    equip_armor(TARMOR"tail_armor");
    equip_armor(TARMOR"vest");
}

