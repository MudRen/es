#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name( "Queen's helmet","��ʤ" );
     add( "id",({ "helmet", }) );
     set_short( "��ʤ" );
     set_long(@C_LONG
��ʤ��Ȼ���Ǹ��˵����Σ�ȴ�紩���Ļ�����Ů�Կɴ���
C_LONG
     );
     set( "weight",50 );
     set( "unit", "��");
     set( "type", "head" );
     set( "material","element" );
     set( "armor_class",6 );
     set( "defense_bonus",2 );
     set( "value",({ 1000,"silver" }) );
     set( "special_defense",(["acid":30]));
}
