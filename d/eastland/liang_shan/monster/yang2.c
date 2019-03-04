#include "../takeda.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(18);
    set_name("Yang Zhi","��־");
    add("id",({"yang","zhi"}) );
    set_short("��־");
	set_long(@C_LONG
��������ޣ������ˣ���������֮���ʵ���������²�����ʮ�˰�
���գ������㾫��ĿǰΪ��ɽ�����������ȷ�ʹ�������������������
����(order)����ͨ����ɽ��Ҫ����
C_LONG
	);
    set("alignment",100);
    set( "gender", "male" );
    set( "race", "human");
    set( "unit", "��" );
    set_perm_stat( "dex",25);
    set_perm_stat( "str",23);
    set_perm_stat( "int",18);
    set_perm_stat( "karma",24);
    set_skill("thrusting",90);	
    set_skill("parry",90);
    set_skill("tactic",95);
    set ("max_hp",550);
    set ("hit_points",550);
    set ("time_to_heal",3);
    set ("wealth", ([ "gold":280]) );
    set_natural_weapon(30,18,30);
	set_natural_armor(45,25);
	set ("aim_difficulty",([ "weakest":40,"vascular":40]) );
	set("special_defense", (["magic":35,"none":20]) );
    set ("weight", 400);
    set( "inquiry", ([
                    "order" :"���ǹ��������������ֻ����ִ��\n"
                    "��Ҫ����Ϊʲ��....\n" ,
                    "why" : "��������㻹�ʣ�С����K ���...\n",
                    "prism" : "�����դ��������ֹ���˽���ģ���ǰ��դ�����ɭ��\n"
                    "�����Ƿǳ��õ��Գ�.....\n",
                    "hunt" : "���Ե����飬�����ȥ���ϻ�������ϲ��������...\n",
                    "�Գ�" : "���Ե����飬�����ȥ���ϻ�������ϲ��������...\n",
                    "����" : "���Ե����飬�����ȥ���ϻ�������ϲ��������...\n",
                    ]) );
    equip_armor(TARMOR"lion_helmet");
    wield_weapon(TWEAPON"ironlance");
    equip_armor(TARMOR"floral_cloak");
    equip_armor(TARMOR"mirror");
    equip_armor(TARMOR"bear_cloth");
}

