#include <mudlib.h>

inherit MONSTER ;

void create ()
{
	::create();
	set_level(18);
	set_name( "thunder dragon", "Ӧ��" );
	add ("id", ({ "dragon"}) );
	set_short( "���� Ӧ��");
	set_long(@CLONG
Ӧ������һ�Ծ�Ө��͸�ĳ��ԭ��ס�ڡ���������ɽ�����϶ˣ�������ˮ��
�ꡣӦ�������ܻƵ۴�ս������У�ǰ��������Ϊ��ʱ��Ȼ����������Ƶ���
�룬Ӧ�����´��꣬�ѵ�����Զ������������Ƶ�ʧ�㣬��Ϊ������Ѱ����˷�
����ʦ�����粮��ʦ����������ˮ��ʹӦ�����硸С�׼����ס���ض����ˡ�����
���ս�ܣ��Ƶ�����Ӧ����������Է����ߵĽ���������졣
CLONG
	);
	set_perm_stat("str", 25 );
        set_perm_stat("kar", 10 );
        set_perm_stat("int", 30 );
	set_skill( "dodge", 100 );
	set( "alignment", 800 );
	set( "hit_points", 800 );
	set( "max_hp", 800 );
        set( "max_fp",400);
	set_natural_weapon( 57, 23, 38 );
	set_natural_armor( 117, 20 );
        set( "tactic", "flank" );
        set("special_defense",(["all":30]));
        set("aim_difficulty",([ 
    	  "critical":80,"vascular":50,"weakest":50,"ganglion":50 ]) );
        set_skill("concentrate",100);
        set_skill("target",100);
        set_skill("black-magic",100);
        set("time_to_heal",5);
        set("spells/lightning",1);
        set("guild_levels/black-magic",50) ;
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
        set_c_verbs(({
                "%s��������צ��%sץȥ",
                "%s������ǳ��������������%sҧȥ"
        }));
        set("tactic_func","my_tactic");
}
int my_tactic()
{
    int i;
    object victim;
    if ( !victim=query_attacker() ) return 0;
    if ( random(14)> 3 ) return 0;
    if ( query_temp("cast_busy") ) return 0;
    for ( i=0;i<2;i++ ) 
       command("cast lightning on "+victim->query("name"));
    set("stop_attack",0);
    return 1;
}
