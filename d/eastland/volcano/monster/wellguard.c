#include "../oldcat.h"

inherit MONSTER;

void create ()
{
	::create();
	set_level(15);
	set_name( "well guard", "��������" );
	set_short( "��������" );
        add("id",({"guard"}));
	set_long( 
             @LONG
һλ���������������峤����������ھ��ģ������������������ͦ���ĵģ�����
��Ҫ��Ϊ�����۸����Ͼ�û������ˢ���ǲ��ᱻ�������õġ�
LONG
	);
	set( "alignment", 200 );
        set( "gender", "male" );
        set( "race", "dwarf" );
        set( "max_hp", 500);
        set( "hit_points", 500);
        set_natural_armor(80,45);
        set_natural_weapon(15,5,10);
        wield_weapon(OWEAPON"spear1");
        equip_armor(OARMOR"cloak3");
        set ("chat_chance", 15);
        set ("chat_output", ({
             "����˵���������!\n",
             "����˵���벻Ҫ�Ҷ�(toss)������������� ?\n",
             "����˵����Ը��������������� ?\n",
             "����˵�������Ͽɹ��벻Ҫ������ɱ��\n",
             }) );
        set ( "inquiry", ([
              "well" : "@@ask_well",
              "water": "@@ask_water",
              ]) );
}

void ask_well(object who)
{
   write("\n����˵����ھ����������˵�������������ҲҪ��ס����\n");
   return;
}

void ask_water(object who)
{
  write("\n����˵����ڿ����� ? ��Ҩһ��ˮ����� !\n");
  write("\n��˵��лл�� !\n");
  write("\n����˵�������� !\n");
  return;
}
