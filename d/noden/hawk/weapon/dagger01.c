
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "golden dagger","�ƽ����" );
        add( "id",({ "dagger","daggercheck" }) );
        set_short( "�ƽ����" );
        set_long(@C_LONG
����Ǯ�δ���ר�õı��꣬��˵Ǯ�δ���ÿɱһ���ˣ��ͻ��ڱ��������
��ɫ��ӣ�������ڱ�����ձ��Ѿ�������ɫ�Ļ��䣬ʵ��̫Ѫ���ˡ�����
�Դ�Ǯ�δ����˳��������ᣬ��ѱ���;ò��ֽ������벻���ڽ����ֱ�
���������............��ϸһ��������Ľ�ɫ���侹Ȼ�Ǽٵ�
C_LONG
        );
        set( "unit", "��");
        set( "weapon_class", 30);
        set( "type", "dagger" );
	set( "min_damage", 15 );
	set( "max_damage", 30 );
        set( "weight", 40 );
        set( "value", ({ 150, "gold" }) );
        set( "second" , 0 );
}

