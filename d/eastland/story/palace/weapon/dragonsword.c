#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name("Sky longsword","ŭ����");
        add ("id", ({"longsword","sword" }) );
        set_short("ŭ����");
        set_long(@LONG
һ�ѽ��������˫��ͷ��̫�׽𾫴��������������İ�ɫ��Դ�ʮ�ɳ���������
������   
LONG
        );
        set("type", "longblade");
        set("unit","��");
        set("weapon_class",35);
        set("min_damage", 20 );
        set("max_damage", 40);
        set("weight", 100);
        set("value", ({ 1000, "silver" }) );
        set_c_verbs( ({ 
           "��%s����ʮ�ɰ�ɫ���б��%s",
           "��Ծ�����ֳ�%sһ����Ӱ��%s�����ȥ",
           "���ٵػӶ�%s������%s��������",
           "׼��ʹ����������ء���һʽ������%s����%s������ݺ�һ��"           
        }) );
}
