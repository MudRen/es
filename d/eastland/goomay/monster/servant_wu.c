#include <../goomay.h>
inherit Mob_special ;
int payed;
void create ()
{
        ::create();
        set_level(4);
        set_name( "Wu the servant", "��������" );
        add ("id",({ "servant","wu"}));
        set_short( "��������");
        set("unit","��");
        set_long(
@C_LONG
�㿴��һ�������С�ĺ��ӣ���ԼĪ����ʮ�꣬���ǿ�����ȴ���ϣ�
Ӫ�����������ϻ������������ȵĺۼ���������һֻ������ר��
���̼�Ժ�е��οͺͼ�Ů��
C_LONG
);
        set("alignment",-350);
        set("wealth/silver",10);
	payed=0;
        set_perm_stat("str",7);
        set_perm_stat("dex",7);
        set_perm_stat("kar",6); 
        set_natural_weapon(5,4,9);
        set ("natural_armor_class", 25);
        set_skill("dodge",65);
        set("natural_defense_bonus",5);
        set ("gender", "male");
        set ("race", "human");
        set( "defense_type","berserk");
        set_c_verbs(({"%s��˫����%s��ץ",
                      "%s�ý���%s����",
                      "%s��ͷ��%sײȥ"}));
       
        set( "inquiry", ([
                "jor" : "@@ask_jor"]));
        set("special_attack",(["damage_type" : "none","main_damage" : 10,
                                "random_dam" : 5 , "hit_rate" : 20]));
        set( "tactic_func", "my_tactic" );
set("c_enemy_msg",
"���������Ĵ������������̵���ˮ��һ���Զ����������ϣ���е�һ���ʹ...\n\n");
set("c_room_msg","��������ˮ����");
set("c_room_msg2", "�������̵����۽� ... \n");
	
}

void init()
{
	::init();
        add_action( "tip_me", "pay");
}
int tip_me(string arg)
{
        string who, type;
        int num;

        if( !arg || arg=="" || sscanf( arg, "%s %d %s", who, num, type)!=3 )
                return notify_fail( 
                        "��˭������Ǯ��\n");
        if( !id(who ) ) return 0;
        if( type != "gold" ) {
               tell_object( this_player(),
                        "����������Ц��: ��ү ! �Բ��𣬽���������н��Ү��\n");
                return 1;
	}
	if (num<50)
	{
		tell_object(this_player(), 
                 "����˵��: ��ү ! С��һ�������ѵ�ֵֻ��ЩǮ��\n" );
		return 1;
	}
	if (num>=50 && payed==0)
	{
                tell_object(this_player(), 
                 "����˵��: ��ү ! С�����֪�޲����� !! ���ʰ� !!\n" );
		payed=1;
                return 1;
	}
        if (num>=500 && payed==1)
        {
                tell_object(this_player(), 
                "����˵��: �� !! ����ʹ���ȥ !! \n�������㴩������Ժ�Ĳ���\n"
		"һ·����Χǽֱ�꣬��������������֪����ǽ�߰���ʲ����أ���\n"
		"ͻȻһ��̤�գ�ֱˤ����ȥ\n.\n.\n.\n.\n.\n.\n");
        this_player()->move_player( Goomay"in_yi_hong", "SNEAK" );
		remove();
                return 1;
	}

}

int ask_jor()
{
if (payed==1)
{
	tell_object(this_player(),
@C_WU
�����������Ȼ���Ѿ�֪���ҵ����ˣ�����Ҳ�ò�����������û�� !! 
������ȷʵ��������Ժ�ڣ�������һ�������صĵط���ֻ����֪������
�������ٸ��������ŵ��ͽ��һῼ��Ҫ��Ҫ����ȥ !! ��Ҫ���ɰ� !!
������������£��㲻����Ȼ���˻������
C_WU
);
        return 1;
}
else
{
tell_object(this_player(), 
	    "����Ц��: ��ү !! ��Ҳ��֪���ģ�С�������ͷ���е���������ȻҲ�ɲ������ !!\n" );
	return 1;
}
}
