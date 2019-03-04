#include <../goomay.h>
#include <stats.h>

inherit Mob_special;
int *c_length = ({ 0,4,8,16,20 });

string *c_song = ({
"�����㣬�������ȸ���磬��������� \n",
"Ҷ�ϳ���Ǭ���꣬ˮ����Բ��һһ��ɾ١� \n",
"����Զ������ȥ����ס���ţ����������á� \n",
"�������������С����ۣ�����ܽ���֡� \n",
"��ǰ��ѹ���˵��δ�ﴺ���Ȳ��ʡ� \n",
"������������գ��˺޲��ط����¡� \n",
"�����Ī�����ף�һ���̳ܽ���ᡣ \n",
"ֱ�뿴����ǻ���ʼ���������ױ� \n",
"��ͥ��ݡ����������һ���ɫ�� \n",
"������������꣬���ұ���һƬ�� \n",
"���·ֻԣ����ӹ�Ӱ�������γ��� \n",
"��Ȼ�Ļᣬ������˵�� \n",
"Ӧ������꣬�¹����գ��ηνԱ�ѩ�� \n",
"�̷���ɧ�����䣬�ȷ����������\n",
"����������ϸ�山��������Ϊ���͡�\n",
"���϶�Ц����֪��Ϧ��Ϧ��\n",
"������űߣ���į��������\n",
"���ǻƻ���Գ��������ꡣ\n",
"�����������һ��Ⱥ���ʡ�\n",
"���������������ֻ������ʡ�\n",

});


void create()
{
	::create();
	set_level(6);
        set_name( "singing girl", "������Ů" );
        add( "id", ({ "girl" }) );
        set_short("������Ů" );
        set_long(
@LONG
����һ�����֡�����͸��ʮ��������Ů������Ȼ���ϵ��·��Ѿ��ƾ��ˣ�
���ǻ���ϴ�ĺ�Ǭ����������һ����\�ã��۾��������ϣ��ڳ����������˺�
��Ե����޼�į�µ�������\�����פ����Ϣһ�£�ֻҪ��(pay)��ʮ����
����������������������ͬʱ�ְ���һ�����ѵ���Ů��
LONG
        );
        set( "gender", "female" );
	set( "race", "human" );
	set_natural_weapon( 7, 6, 14 );
	set_natural_armor( 35, 12 );
	set_perm_stat( "dex", 12 );
	set_perm_stat( "str", 12 );
	set_skill( "dodge", 60 );
	set("defense_type","dodge");
	set( "wealth/gold", 1 );
        set_natural_weapon( 20, 6, 16 );
        set_natural_armor( 30, 10 );
        set_c_verbs(({"%s��ָ��ץ��%s","%s����\������%s","%s�ý�����%s"}));
        set("special_attack",(["damage_type" : "none","main_damage" : 10,
                                "random_dam" : 5 , "hit_rate" : 20]));
        set( "tactic_func", "my_tactic" );
set("c_enemy_msg",
    "������Ů��������\���������������..\n\n");
set("c_room_msg","������Ů����������\��ɨ��");
set("c_room_msg2", "�����壬������ýŲ����� ...\n");
}

void init()
{
	::init();
	add_action( "do_fortell", "pay");
}
void sing(int i,int j)
{
 tell_room(environment(),c_song[i] ,this_object());
 i++;
if (i<j)
 call_out("sing",3,i,j);
 else
 tell_room(environment(),
   "\n��\�����������򲻿��š���\n"
   "������Ů΢΢һ��������������л��λ��ү !!\n",this_object());
 return;
}

int do_fortell(string arg)
{
	string who, type, race;
	int num, age,song_no=0;

	if( !arg || arg=="" || sscanf( arg, "%s %d %s", who, num, type)!=3 )
		return notify_fail( 
			"��˭������Ǯ��\n" );
	if( !id(who ) ) return 0;
	if( type != "gold" ) {
		tell_room( environment(), 
			"������Ů˵��: �Բ��𣬿͹� ! ��ֻ�ս�ҡ�\n" ,
			this_object() );
		return 1;
	}
if( !this_player()->debit(type, num) ) return notify_fail(
	"�͹� ! ���㲻Ҫ�۸�һ��������Ů������������û��������� !\n");
	if( num < 10 ) {
		write(
			"������Ů�������һЦ��ҡһҡͷ����Ǯ�˻����㡣\n");
		this_player()->credit(type, num);
		return 1;
	}
	if ( num >=10){
        tell_room( environment(),
		"������Ů���ڳ�����һ�������������׳��ˡ�\n"
		"˵�ϣ�����ز���������\�ã�����������\n\n",this_object());
	song_no=random(4);
	call_out("sing",2,c_length[song_no],c_length[song_no+1]);

	return 1;
	}
}

