#include <mudlib.h>

#define DETECT_ALI(x) (int)x->query("alignment") 
#define DETECT_SCORE(x) (int)x->query("war_score")
inherit WEAPON;

void create()
{
    set_name( "blood sword","��Ѫ��" );
    add("id",({"blood","sword"}) );
    set_short( "��Ѫ��" );
    set_long(@C_LONG
һ�ѽ���ʺ�ɫ�ĳ�������Ѫ������Դ�Ѳ��ɿ�,ֻ֪����������ʱ��һλΰ���
����ʦ�Ƴɡ���ѽ�����һ�β�Ϊ��֪����ʷ;�뵱����λ����ʦΪ������ѽ���
������,��ϧͶ��춻�¯֮��,����ڽ����ƺ�������һ˿˿��ɫ��Ѫ����
C_LONG
            );
    set("unit","��");
    setup_weapon("longblade",20,15,15);
    set("weight",50);
    set("value",({400,"silver"}) );
}
