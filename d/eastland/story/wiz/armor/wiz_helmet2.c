#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("medicine hat","ҩʦ��ͷ");
        add( "id", ({ "hat" }) );
        set_short("ҩʦ��ͷ");
        set_long(@C_LONG
һ���ð�����������ɽ����״��ͷ������ͷ����Ϳ�з��������ҩ�ģ�Ψһ��ȱ��
�ǲ�����
C_LONG
        );
        set( "unit","��");
        set( "type", "head" );
        set( "material","healer");
        set( "armor_class",7 );
        set( "defense_bonus",4);
        set( "weight", 40 );
        set( "value", ({ 800, "silver" }) );
        set("special_defense",
             (["evil":20,"poison":20,"fire":-20,"cold":-20]) );
}



