#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "black camisole","��ɫ������" );
        add( "id", ({ "black camisole","camisole" }) );
        set_short( "��ɫ������" );
        set_long(
 "һ�׺�ɫ�Ľ����£���������������Ů���������ʺϲ������ˡ�\n"
        );
        set( "unit", "��" );
        set("material","thief");
        set( "type", "body" );
	set( "armor_class", 33 );
	set( "defense_bonus", 5 );
        set( "weight", 90 );
        set( "value", ({ 1500, "silver" }) );
	set( "extra_skills", ([ "backstab" :10 , "sneak" :-15 ]) );
        set( "special_defense",(["evil":10,   "fire":-15,]));

}

int stop_equip()
{	
        if ((string)this_player()->query("gender") != "female")
        {
                tell_object(this_player(),@LONG
��ƴ����Ҫ����������þ����Ľ����£�ȴ�����Լ���͹�ĵط���͹��
�ð��ĵط��������������й��ѿ���һ��֮�¾Ͱ��·���˺���ˡ�
LONG
                );
        call_out( "tear_cloth", 2 );
        return 1;
        }
      return 0;
}

void tear_cloth()
{
   this_object()->remove();
}
