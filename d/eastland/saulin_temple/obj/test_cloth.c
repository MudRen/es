	set( "equip_func", "angel" );



void angel()
{
string name; 
object holder;

 holder = environment(this_object());
 name=(string)holder->query("name");
 if (name!="angel") {

     tell_object( holder, can_read_chinese(holder)?
     "\n\n�·�ͻȻ���һ���â�����ƺ���Ը������㣬�ĵ�һ�������Ĵ�����һ��
���ܵ����ص��˺���\n"
        this_object()->move(environment(environment(this_object())) );
                   }
       else {

    tell_object( holder, can_read_chinese(holder)?
 bold("\n���ҷ��ӱ��µ��쵼���������ȥ��ɱ����������!!!���·�����һ���Ц
�����Ǳ����ˣ�Ҫ���Ͱ�!���㷢���������������������Ѫ...\n"):
         "\nThe sword obeyb your control.\n" );
	holder->receive_damage(40);
            }   
}

