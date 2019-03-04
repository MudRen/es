#include <mudlib.h>

#define INT(x)  (int)x->query_perm_stat("int")
#define ALI(x)  (int)x->query("alignment")
#define NAME(x) (string)x->query("c_name")
inherit WEAPON;

void create()
{
    set_name( "seven-star shortsword","���� ���ǽ�" );
    add("id",({"shortsword"}) );
    set_short( "���� ���ǽ�" );
    set_long(@C_LONG
���ǽ��Ľ��������߿��߲ʱ�ʯ,�ֱ������������ǵķ�ʽ���С����ǽ�ԭ������
���������, ����������ʱ������׿������������ʧ�˺�һ����, ֱ������̫�桻
�ھ������꡻ʱ�������˳������ഫ���ǽ�һ��, �ͻ����������һ����ƽ�,
����׿����������һ����õ����ӡ�
C_LONG
            );
    set("unit","��");
    setup_weapon("shortblade",30,15,20);
    set("weight",30);
    set( "bleeding", 10 );
    set("value",({2400,"silver"}) );
    set( "wield_func","wield_shortsword");
    set( "unwield_func","unwield_shortsword");
    set_c_verbs( ({ "�ֳ�%s���󽣾�,ʹ����һʽ���׺���ա����ٵش���%s",
                    "��%sˢˢˢ������,�ɿ�ؿ���%s",
                    "��%s����һ,һ����Ӱ������%s",
                    "��%s��׼%sһ��,Ȼ���ּ��˻���",
                  }) );   
}
