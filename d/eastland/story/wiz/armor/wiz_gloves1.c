#include <mudlib.h>
inherit ARMOR;
void create()
{
     set_name( "medicine gloves","ҩʦ����" );
     add( "id",({ "gloves"}) );
     set_short( "ҩʦ����" );
     set_long(@C_LONG
һ���Դ����Ƴɵ����ס���ҩʦ���������ر�Ϳ�Ϸ��������ҩ�ģ���ȴ�����ա�
C_LONG
     );
     set( "weight",40 );
     set( "unit", "��");
     set( "type", "hands" );
     set( "material","healer" );
     set( "armor_class",4 );
     set( "defense_bonus",3 );
     set( "value",({ 800,"silver" }) );
     set("special_defense",
        (["evil":20,"poison":20,"fire":-20,"cold":-20]) );
}
