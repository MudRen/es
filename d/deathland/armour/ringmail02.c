#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("Luck ringmail","���˻���");
        add("id",({"ringmail"}) );
         set_short( "a luck ringmail","���˻���");
	set_long(
"This is a suit of ringmail made of mithril meterial,which can  \n"
"protect your body against opponent's attacks.\n",
"����һ������,���Ա�����ֿ����˵Ĺ���,��˵�����⻷�׵�����ս�����ܹ�����\n"
"�ıܿ����˵��ػ�.\n"
	);
	set( "unit", "��" );
	set( "weight", 250 );
	set( "type", "body" );
	set( "material", "light_metal");
	set( "armor_class", 22 );
	set( "defense_bonus", "@@luck_bonus" );
	set( "value", ({ 188, "gold" }) );

}

int luck_bonus()
{ 
    int bonus;
    
    bonus= 2 +random(5);
    return bonus;
}     
