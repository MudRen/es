
#include "../goomay.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(4);
        set_name( "servant", "Ƥ��" );
        set_short( "Ƥ��");
        set("unit","λ");
        set_long(
@C_LONG
�㿴��һ������ĺ��ӣ���ԼĪ����ʮ���꣬���ǿ�����ȴ���ϣ�
Ӫ�����������ϻ������������ȵĺۼ���һ˫ˮ����ȴ����ÿ������
���ˣ�������Щ�Ƚ���ʵ�����е���˼���ο;���ǰһ���ҳ�������
���������Щ�������ĵĻ���������֪�ܡ�
C_LONG
);
        set("alignment",-350);
		set("wu_appear",0);
        set("wealth/silver",15);
        set_perm_stat("str",7);
        set_perm_stat("dex",8);
        set_perm_stat("kar",6); 
        set_natural_weapon(5,4,9);
        set ("natural_armor_class", 25);
        set_skill("dodge",45);
		set( "defense_type","dodge");
        set("natural_defense_bonus",5);
        set ("gender", "male");
        set ("race", "human");
        set_c_verbs(({"%s��˫����%s��ץ",
                      "%s�ý���%s����",
                      "%s��ͷ��%sײȥ"}));
       
        set( "inquiry", ([
                "wu" : "@@ask_wu"]));
	
}
int appear_wu(object who)
{
	object ob;
	tell_room( environment(), 
	"һ������һֻ�����İ�С���ӣ�һ��һ�ε����˹��� ...\n" ,
	who );
        new(Mob"servant_wu" )->move( environment() );
	return 1;
}
int ask_wu()
{
if ( query("wu_appear") ) {
tell_object(this_player(),
@C_WUA
��Ƥ����һ���۾�����������´����㣬��аа��Ц��������Ｑ�� !! 
�Ѿ�������ˣ��š����ǲ����������������� ������
C_WUA
);
return 1;
}

tell_object(this_player(),
@C_WU
��Ƥ����һ���۾�����������´����㣬��аа��Ц��������������Ժ����
���ȴҪ��һ������������ˣ��ٺ� !! ������������ɤ������ְҵ��
�Ĵ�ɤ�Ŵ󺰣����������� ������������ �����������˶���Ȼ��Ц��
C_WU
);
	set("wu_appear",1);
        call_out("appear_wu", 5,this_object());
        return 1;
}
