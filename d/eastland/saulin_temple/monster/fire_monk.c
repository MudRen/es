#include <mudlib.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(14);
        set_name( "fire monk", "��ͷ��" );
        add ("id", ({ "monk" }) );
        set_short("��ͷ��");
        set("unit","λ");
        set_long(@C_LONG
�㿴��һλ�����������⣬����һ���˾�������ˣ�������ҪͶ�����ֵ�
���У�������ΪƷ�Բ��ѣ�û�˿ϰ�����ȣ�������������һЩ�ջ���
�Ĵֻ��Ϊ�������У��������Գƻ�ͷ�ӡ�
��������������Ǽ٣�͵ѧ�书\���棬��һ����͵����(book)�����ˡ�
C_LONG
        );
        set( "inquiry", ([
             "book" : "@@ask_book"  ]));

        set("alignment",-1200);
        set("wealth/silver",200);
        set_perm_stat("str", 20);
        set_perm_stat("dex", 22);
        set_skill("parry",80);
        set_skill("dodge",80);
	set_skill("unarmed",100);
        set_natural_weapon(20, 19, 25);
        set_natural_armor(70, 30);
        set("max_hp", 600);
        set("hit_points", 600);
        set("max_fp", 1800);
        set("force_points", 1800);
	set("force_effect",2);
        set("special_defense", ([ "all" : 25, "none" : 10 ]) );
        set("aim_difficulty", ([ "critical" : 20, "vascular" : 10,]) );
        set("gender", "male");
        set("race", "human");
        set_c_verbs(({ "%sʩչ�������ָ��%s��ȥ", "%s�ý��������%s",
                       "%s����ͷ��\һͷ��%sײȥ" }));
}

void ask_book(object player)
{
    tell_object( this_player(), @ALONG
         ��ͷ������һ���Σ�аЦ����
         �㷢�������ӵ����ܣ���������߳�������
         
ALONG
                );
    kill_ob( player );
}

void die()
{
    object killer;

    if ( killer = query("last_attacker") ) {
    killer->set_temp("book_quest/step",2);
    tell_object(killer,@DIE
    
  ���� ������ �Ҳ�Ҫ�����������Ұ�!!��
  
��ͷ�ӵ��ڵ��Ͽ�����Ѫ���ۼ��ǲ�����! ��ͻȻ���в��̣�
��Ǳ��������ȣ���ס����һ����

  ��лл�� ! ���������û��͵����!! ��֪���˺�����������ᣬ�ͳ���
    �����￴�飬���Ҵ�������Ҳû�б�Ҫ������ߣ�����Ĳ�����͵��!!��

�����룬һ���ڿ���Ʈ�����ȷ�Ӳ����������۾���������������ͷ
�Ӱ������Ȼ��ȥ���ɴ�ʦ����(report)��ϸ�����Ρ�

DIE
    );
    }
    call_out("remove",0);
}
