
#include "../zeus.h"
inherit WEAPON;

void create()
{
        set_name( "dragon longsword ", "���ν�" );
        add( "id",({ "sword", "dragon","longsword" }) );
        set_short( "a dragon longsword", "���ν�" );
        set_long(@CLONG
���ν��������ִ���������ɮ����֮һ���������ν�֮�Ƴ��֣��˽�
�˶��Ѵ�ʦ���У����Ͽ���ʫԻ��
        ���������ֱ�������������ͷ��β������
        ��������������Խ���磬��ʱ�������ɽ
      �������������ܴ̾�ʯ�ã�����˫��������
CLONG
);
        set( "unit", "��");
        set( "weapon_class", 38 );
        set( "type", "longblade" );
        set( "min_damage", 24 );
        set( "max_damage", 44 );
        set( "weight", 190 );
        set( "value",({ 300, "gold" }) );
        }