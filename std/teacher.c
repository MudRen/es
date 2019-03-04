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
	int skill, exp;

	if( !arg || arg=="" || undefinedp(lessons[arg]) )
		return notify_fail( can_read_chinese()?
			"��Ҫѵ��ʲ�Ἴ�ܣ�\n": "Train what?\n" );

	if( !this_object()->check_trainee( this_player() ) )
		return 0;

	skill = (int)this_player()->query_skill(arg);
	if( skill > lessons[arg][1] )
		return notify_fail( can_read_chinese()?
			"�������������ֻ��ѧ�� " + lessons[arg][1] + "��\n":
			"You have learned all you can learn here.\n" );

	exp = (int)STATS_D->query_skill_exp(skill) * lessons[arg][0] / 100;
	if( exp > (int)this_player()->query_exp_stock() )
		return notify_fail( can_read_chinese()?
			"�����������Ҫ " + exp + " �㾭�飬������ľ��鲻����\n":
			"You need " + exp + " experience to train this skill.\n" );

	this_player()->gain_experience( -exp );
	STATS_D->train_skill( this_player(), arg );
	write( can_read_chinese()?
		"���" + to_chinese(arg) + "�������������� " + 
		this_player()->query_skill(arg) + " �ˡ�\n":
		"Your " + arg + " skill is now " + this_player()->query_skill(arg) + ".\n" );
	return 1;
}
