//#pragma save_binary

// teacher.c
#include <daemons.h>

mapping lessons;

// This function initializes the lessons the trainer can teach.
void set_lessons( mapping available_lessons )
{
	lessons = available_lessons;
}

void init()
{
	add_action( "do_train", "train" );
}

int check_trainee( object trainee ) { return 1; }

int do_train(string arg)
{
	int skill, exp, explore,EXPLORE1,total_points;

	if( !arg || arg=="" || undefinedp(lessons[arg]) )
		return notify_fail( 
			"��Ҫѵ��ʲ�Ἴ�ܣ�\n" );
        explore  = (int)this_player()->query_explore_points();
	total_points=EXPLORE_D->query_total_explore();
	EXPLORE1=explore*100/total_points;
	if (EXPLORE1 > 100) EXPLORE1 =100;
	
	if( EXPLORE1 < lessons[arg][2] )
	        return notify_fail("������˵��: û��ð�վ����ð���ߣ���ֵ���Ҵ��ڼ���!\n");
	if( !this_object()->check_trainee( this_player() ) )
		return 0;

	skill = (int)this_player()->query_perm_skill(arg);
	if( skill > lessons[arg][1] )
		return notify_fail( 
			"�������������ֻ��ѧ�� " + lessons[arg][1] + "��\n");

	exp = (int)STATS_D->query_skill_exp(skill) * lessons[arg][0] / 100;
	if( exp > (int)this_player()->query_exp_stock() )
		return notify_fail( 
			"�����������Ҫ " + exp + " �㾭�飬������ľ��鲻����\n");

	this_player()->gain_experience( -exp );
	STATS_D->train_skill( this_player(), arg );
	write( "���" + to_chinese(arg) + "�������������� " + 
		this_player()->query_perm_skill(arg) + " �ˡ�\n");
	return 1;
}
