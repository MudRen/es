#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
        set_name( "lan-hwa lun", "��������");
        add( "id", ({ "shield","lun" }) );
        set_short("��������");
        set_long(@C_LONG
������һ�ַ𷨵ľ���, ���з���������˫�ص�Ч��, ����������
����������������֮����, ƽʱ�ɵ�������ʹ��, ��ħ���ϡ�        
C_LONG
		);
        set( "unit", "��"); 
        set( "type", "shield" );
        set( "material", "monk" );
        set( "armor_class", 8 );
        set( "defense_bonus", 4 );
        set( "weight", 110 );
        set( "value", ({ 120, "gold" }) );
}
