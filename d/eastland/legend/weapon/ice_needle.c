#include <mudlib.h>
inherit WEAPON;

void create()
{
    set_name("ice needle","��������");
    add("id",({"needle","dagger"}) );
    set_short("��������");
    set_long(@C_LONG
������������ǧ�꺮���Ƴɡ����뱾������͸��һ����ĺ���,��ʹ���������Ҳ
�ܸ��ܡ�
C_LONG
       );
    set("unit","��");
    setup_weapon( "dagger",37,19,33);
    set("weight",40);
    set("value",({350,"gold"}));
    set("extra_skills",(["anatomlogy":10]));
}
