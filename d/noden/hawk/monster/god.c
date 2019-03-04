#include <mudlib.h>
#include "/u/s/smore/hawk.h"
inherit MONSTER;

void create ()
{
        ::create();
        set_level(7);
        set_name("Hawkman Flamen","�������˾");
        add("id",({"","hawkman","flamen"}) );
        set_short("�������˾");
        set_long(@C_LONG
�㿴��һ���ڼ�̴�ϳ���������ͷ�ӣ������������ļ�˾�ɡ����������
���˵�����Ѿ��þúþ��ˣ�Ӧ��֪��һЩ��̳�Ĺ���(story)�ɡ�
C_LONG
        );
        set("alignment",300);
        set( "gender", "male" );
        set( "race", "hawkman");
        set( "unit", "λ" );
        set_perm_stat( "dex",5);
        set_perm_stat( "int",12);
        set_perm_stat( "karma",3);
        set_natural_weapon(12,10,20);
        set_natural_armor(25,10);
        set("inquiry",([
                "story":"@@ask_story",
                        ]) );
        set("aim_difficulty",(["critical":30, "vascular":30]) );
}


int ask_story()
{
        tell_object(this_player(),@LONG
�������˾����˵��
������̳���¾���ÿ������䶷���ĵط����μӱ������ʿ��������������ף
��������������������䶷������������Ӻڰ��������Ĺ���治֪��������
Щʲ�ᣬ���ϺͰ�����Ҫ�ǲ���ȡһЩ�ж�������һ���ᷢŭ�ġ�
LONG
        );

        return 1;
}
