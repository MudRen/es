#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("night-Ghost amulet","��ħ������");
        add( "id", ({ "amulet"}) );
        set_short( "��ħ������");
        set_long(@C_LONG
��ħ�������ഫ����������ʮ���죬�ɾŸ����������ʮ������Ůͯ������ش���
�������ǾŸ�������Ƴɵģ���춴˷������ͣ�������֮���ǳ����˱�����ؽ��
֮�ᣬ����Ͳ�֪�����䣬��˵������շת���롸�������ȳ���֮�֡�
C_LONG
        );
        set("unit","��");
        set( "type", "misc" );
        set("material","cloth");
        set( "defense_bonus", 6 );
        set( "weight",5 );
        set("special_dfense",
                     (["evil":20]) );
        set( "value", ({ 2500, "silver" }) );
}



