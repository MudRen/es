#include <mudlib.h>

inherit WEAPON;

void create()
{
    set_name("Koku Sword","������");
    add("id",({"koku","sword"}) );
    set_short("������");
    set_long(@C_LONG
�Ǵ�˵��ħ�˺����Ľ���������ʳʧ���ߵ�Ѫ���������ѻ�Ϊ
��������
C_LONG
    );

    set("unit","��");
    set("weight",150);
    set("type","longblade");
    set("weapon_class",30);
    set("min_damage",12);
    set("max_damage",32);
    set("value",({600,"silver"}) );
}
