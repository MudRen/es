#include "../saulin_temple.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(17);
        set_name( "shu ju", "ɨ��ɮ ����" );
        add ("id", ({ "monk","shu","ju" }) );
        set_short( "ɨ��ɮ ����");
        set("unit","λ");
        set_long(@C_LONG
���������ڶ�ĸ�ɮ�У�����Ҫ������û���������ˡ����������ʱ��Ϳ�ʼ
����ؾ�¥�Ĵ�ɨ������ƽ�����ٸ����Ӵ���������������֪������Ҳû��
�����ˡ����Ƕ�������ɨ�ؾ�¥�Ľ�����������������еľ��飬���������
Ҫ�������۾���Ļ�����Ӧ��������ʵ���ѡ�ˡ�
C_LONG
        );
        set("alignment",2000);
        set("wealth/silver",38);
        set("gender","male");
        set("race","human");
        set("chat_chance",10);
        set("max_hp", 600);
        set("hit_points", 600);
        set("max_fp", 400);
        set("force_points", 400);
        set("special_defense", ([ "all" : 45, "none" : 40 ]) );
        set("aim_difficulty", ([ "critical" : 50, "vascular" : 50 ]) );
        set_perm_stat("str", 24);
        set_perm_stat("dex", 28);
        set_perm_stat("pie", 30);
        set_perm_stat("kar", 18);
        set_natural_weapon( 35, 20, 35 );
        set_natural_armor( 75, 20 );
        set_skill("dodge",100);
	set("defense_skill",CLASS"body_def");
	set("monk_gonfu/body-def",10);
        set_skill("bo",100);
        set ("chat_output",({
        	"����˵��������ؾ�¥������С͵�����˼�������(sutra)��\n"
        }));
        wield_weapon( SAULIN_OBJ"whisk" );
//	equip_armor( SAULIN_OBJ"boot2" );
//	equip_armor( SAULIN_OBJ"shield3" );
        equip_armor( SAULIN_OBJ"grey_pallium" );
        equip_armor( SAULIN_OBJ"ring3" );
        set("inquiry",(["sutra":
@C_LONG
���������㾭���ʱ���ֵ��˼������󲿷ֶ����Ǻ���Ҫ��
���飬����������һ��㶼Ӿ��ƺ������ر����ӣ�Ҫ������һ��Ҫ�һ�������
���Ȿ����������о��𾭵�����˵�����Ǻ���Ҫ��ʵ���е���֡�������Ȼ
�Ƿ��ɵ���˼������ֻ����������
C_LONG
]));

}

