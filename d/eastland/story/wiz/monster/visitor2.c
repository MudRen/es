#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(15);
	set_name( "visitors", "һ��Ⱥ�۹��ÿ�" );
	set_short( "һ��Ⱥ�۹��ÿ�" );
	set_long(@C_LONG
���Ǵ����������۹���ÿͣ������Ǿ��������Ǯ�����ӣ�һ��ʤ��һ����һ��
������һ�����������£���֪�Ǵ��Ƕ����������Ǳ�����һ�㣬����������֮��
��
C_LONG
        );
        set( "wealth/silver",300);
        set( "alignment",-1000);
        set( "unit","");
        set( "gender","neuter");
        set_natural_armor(75,0); 
        set_natural_weapon( 27,14,28 );
}
