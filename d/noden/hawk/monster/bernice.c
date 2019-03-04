inherit MONSTER;
void create()
{
        ::create();
        set_level(3);
        set_name( "Bernice","����˿" );
        add("id",({"bernice"}) );
        set_short( "����˿" );
        set_long(@LONG
�㿴��һλͤͤ��������Ů����������ף�ϸ�µ�Ƥ������������ȴ������
���ĳ�˼����������԰����ࡡ�
LONG
        );
        set( "inquiry", ([
                "help" : "@@help_me",
                "traito" : "@@ask_traito",
                "vito" : "@@ask_vito",
                "adolph" : "@@ask_adolph",
                ]) );
        set( "alignment", 100 );
        set( "gender","female" );
        set( "race","hawkman" );
        set( "time_to_heal", 10 );
        set_natural_armor( 20, 12 );
        set_natural_weapon( 25 , 13 , 17 );
        set( "wealth/silver", 300 );
}

int help_me()
{

        if ((int)this_player()->query_temp("find_ring") == 1 &&
           (present("blue ring",this_object())) )
        {
                tell_object(this_player(),@LONG
����˿һ���������еĽ�ָ����ɫ���....
��̾�˿�����˵����....�����˵��������
....������Ӧ��֪�������崫ͳ�ı�����ɡ����������ʤ�߿��Ի��
����������ĵ�λ��Ҳ����ҵİ���ά��(Vito)�������ݺ��ˡ���һֱ��Ҫ
�ҵ�����������䣬����ƽ�����ܵ��˺���ϴˢ���ĳ��裬��ȴһֱ�޷�ʵ
�֡�����˿̧��ͷ�����������˵���������Զ���������˵����ϣ��������
�ϰ�����....
��һ����Ѫӿ����ͷ����������˿˵���һ�����㣬���㲻�ٱ���....
LONG
                );
                this_player()->set_temp("bernice",1);
                this_player()->delete_temp("find_ring");
                return 1;
        }
        else if (this_player()->query_temp("smore_box") == 6)
        {
                tell_object(this_player(),@LONG
����˿˵��
        лл�㣬��ά���ܹ��Ŀ������
������ˡ���������֮�ա������񣬵õ� 8000 �㾭���ı��ꡣ
LONG
                );
		this_player()->set_explore("noden#43");
		if ((int)this_player()->query_quest_level("vito's_wish") < 1) {
		this_player()->finish_quest("vito's_wish",1);
		this_player()->gain_experience(8000);
		}
        }

        else
        {
                tell_object(this_player(),@LONG
����˿������һ�ۣ�˵���ⲻ������¡�
LONG
                );
                return 1;
        }
        return 1;
}


int ask_vito()
{
        if ((int)this_player()->query_temp("bernice") == 1)
        {
                tell_object(this_player(),@LONG
����˿����ͷ˵��
ά�����ҵ�δ���Ҳ������Ŀ�е�Ӣ�ۡ���֪���Ӷ����ǰ������һֱ����
��������䣬�쵼���������սʿ�ǶԿ������ĵ��ˣ�һ����һ�εĻ�����Ҫ
Ⱦָ���֮�ǵĵ��ˡ�����ȴ��һ����ǰ�ı������аܸ������ĵܵܣ�����
��(Adolph)��������ֵ��ǣ���������û�������������治֪��Ϊɶ����һ
��֮���书ͻ���ͽ����ѵ�����Ϊ͵�Խ�ҩ��
����˿������˵��
��������������ε�ά�࣬���ݷ����˵������������ȴ����������ֻ����Լ
Լ����ʲ���׶�(Traito)����....
LONG
                );
                this_player()->set_temp("traito",1);
                return 1;
        }
        else
        {
                tell_object(this_player(),"����˿�������㡣\n");
                return 1;
        }
        return 1;
}

int ask_adolph()
{
        if ((int)this_player()->query_temp("bernice") == 1)
        {
                tell_object(this_player(),@LONG
����˿˵��
������....��ά��ĵܵܣ�ά��һ�����չ����ģ�������һ�����ն���ǿ��
��֪��Ϊʲ�����ȥ��һ�ٻ����ҵ�ά�࣬���ҿ��������������ڱ��䣬����
�����ά������������������������������֮�ᣬ��֪�������������һ��
ʲ���������̴��˾����������(Juraken) �ģ�������������һ�𣬶��һ�Ҫ
�����������սʿ��Ϊ���ֿ����ĵ��ˡ�������ǰ��һ����ս������Ԫ������
����Ҷ԰������Ǹ�ŭ�������ԡ�
LONG
        );
                return 1;
        }
        else
        {
                tell_object(this_player(),"����˿�������㡣\n");
                return 1;
        }
}

int ask_traito()
{
        if ((int)this_player()->query_temp("traito") == 1)
        {
                tell_object(this_player(),@LONG
����˿˵���׶���ά����ǰ�����εĲ��£�����ά����������ü��Σ���
��ά��ʧ�٣������ܵ��˰��������ʶ����λԽ��Խ�ߡ���Ϊά��Ĺ�ϵ����
���չ��ң��������������������ֵֹģ���֪�������ˡ�
LONG
                );
                return 1;
        }
        else
        {
                tell_object(this_player(),"����˿�������㡣\n");
                return 1;
        }
        return 1;
}

