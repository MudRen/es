#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("The Archmaster's amulet","����ʦ������");
        add( "id", ({ "amulet" }) );
        set_short( set_color("����ʦ������","HIY"));
        set_long(@C_LONG
һ�Ų�ʱ��ҫ����ɫ���ƵĻ�����������Щ������������������֡�
C_LONG
        );
        set("unit","��");
        set( "type", "misc" );
        set("material","cloth");
        set( "defense_bonus", 8 );
        set( "weight", 5 );
        set("special_defense",
           (["evil":30,"poison":30,"fire":-30,"cold":-30]) );
        set( "value", ({ 5050, "silver" }) );
}



