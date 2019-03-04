#include "../goomay.h"
inherit ARMOR;

void create()
{
        set_name( "flame shield", "�����");
        add( "id", ({ "shield" }) );
        set_short("a flame shield", "�����");
        set_long(
           "This is a magic shield which made by element of fire .\n",
           "����һ���ɻ��澫���������ɵ�ħ�ܣ���˵����ħ������ԶԶ����һ���ħ���ܡ�\n"
        );
        set( "unit", "��"); 
        set( "type", "shield" );
        set( "armor_class", 5 );
        set( "defense_bonus", 2 );
        set("material","element");
        set( "weight", 150 );
        set( "no_sale",1);
        set("special_defense",(["cold":30, ]));
        set("extra_stats",(["dex":-1,"con":-2 ,]));
        set("extra_skills",(["shortblade":10,]));
        set( "value", ({ 350, "gold" }) );
}
