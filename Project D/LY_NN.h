//
//  LY_NN.h
//  NN_Dev
//
//  Created by Logan Yliniemi on 4/3/17.
//  Copyright © 2017 Logan Yliniemi. All rights reserved.
//

#ifndef LY_NN_h
#define LY_NN_h


#include <vector>
#include <math.h>
#include <map>
#include <assert.h>

#define LYRANDOM ((double)rand()/RAND_MAX)
#define BEGIN (0.001)

using namespace std;


/// BGN NON NNV, BUT NECESSARY FUNCTION BLOC
#define TRIG_GRANULARITY 1000
double sine(double inp){
    //return sin(inp);
    
    double outp;
    static map< int, double > sine_iomap;
    int input_int = inp*TRIG_GRANULARITY;
    if(sine_iomap.count(input_int) == 1)
    {outp = sine_iomap.find(input_int)->second;}
    else{
        outp = sin(inp);
        sine_iomap.insert(pair <int,double> (input_int,outp));
    }
    return outp;
}
double cosine(double inp){
    //return cos(inp);
    
    double outp;
    static map< int, double > sine_iomap;
    int input_int = inp*TRIG_GRANULARITY;
    if(sine_iomap.count(input_int) == 1)
    {outp = sine_iomap.find(input_int)->second;}
    else{
        outp = cos(inp);
        sine_iomap.insert(pair <int,double> (input_int,outp));
    }
    return outp;
}
/// END NON NNV, NECESSARY FUNCTION BLOC

class neural_network;
class layer;
class node;

class node{
    friend class layer;
    friend class neural_network;
    
    double min;
    double max;
    
    void sigmoid();
    void true_sigmoid();
    
    double inp;
    double outp;
    vector<int> outconnections;
    vector<double> outweights;
    void clean();
    void setup(int,int);
    void make_full_connected(int);
    
    void output_floor();
    void output_ceiling();
    
    bool bias;
    
public:
    void zero_weights();
    double get_average_outweights();
};

double node::get_average_outweights(){
    double num=0.0;
    for(int i=0; i<outweights.size(); i++){
        num+=fabs(outweights.at(i));
    }
    num/=outweights.size();
    return num;
}

void node::zero_weights(){
    for(int i=0; i<outweights.size(); i++){
        outweights.at(i)=0;
    }
}

void node::make_full_connected(int num){
    for(int i=0; i<num; i++){
        outconnections.push_back(i);
        outweights.push_back(LYRANDOM*BEGIN-LYRANDOM*BEGIN);
    }
}

void node::clean(){
    inp=0;
    outp=0;
}
void node::setup(int mi, int ma){
    clean();
    min=mi;
    max=ma;
}

class layer{
    friend class node;
    friend class neural_network;
    vector<node> layer_nodes;
    void clean();
};

class neural_network{
    friend class node;
    friend class layer;
    
    vector<double> input_values;
    vector<double> input_minimums;
    vector<double> input_maximums;
    
    vector<double> output_values;
    vector<double> output_minimums;
    vector<double> output_maximums;
    vector<double> recorded_outputs;
    
    layer input;
    layer hidden;
    layer output;
    
    int intended_size;
    
public:
    void setup(int num_in,int num_hid,int num_out);
    void set_vector_input(vector<double> whole_input);
    void set_weights(vector<double> user_input, bool safe);
    void execute();
    void clean();
    
    
    void set_in_min_max(double,double);
    void set_out_min_max(double,double);
    double get_output(int);
    int get_number_of_weights();
    
    void disp_outputs();
    void zero_weights();
    void display_out_min_max(int);
};

int neural_network::get_number_of_weights(){
    return intended_size;
}

void neural_network::set_weights(vector<double> user_input, bool safe){
    if(safe){
        if(user_input.size() != intended_size){
            cout << "Size of vector passed does not match necessary size" << endl;
            cout << "User input size: " << user_input.size() << endl;
            cout << "Necessary size: " << intended_size << endl;
            cout << (2*3 + 4*1) << endl;
        }
        assert(user_input.size() == intended_size);
    }
    
    int z=0;
    /// for each input node
    for(int i=0; i<input.layer_nodes.size(); i++){
        /// for each weight attached to the input node
        for(int j=0; j<input.layer_nodes.at(i).outweights.size(); j++){
            input.layer_nodes.at(i).outweights.at(j) = user_input.at(z);
            z++;
        }
        
    }
    
    /// for each hidden node
    for(int i=0; i<hidden.layer_nodes.size(); i++){
        /// for each eight attaced to the hidden node
        for(int j=0; j<hidden.layer_nodes.at(i).outweights.size(); j++){
            hidden.layer_nodes.at(i).outweights.at(j) = user_input.at(z);
            z++;
        }
    }
    return;
}


void neural_network::zero_weights(){
    for(int i=0; i<input.layer_nodes.size(); i++){
        input.layer_nodes.at(i).zero_weights();
    }
    for(int h=0; h<hidden.layer_nodes.size(); h++){
        hidden.layer_nodes.at(h).zero_weights();
    }
}

void neural_network::disp_outputs()
{
    cout << "DISP " << output_values.size() << ":";
    for(int i=0; i<output_values.size(); i++)
    {
        cout << output_values.at(i) << "\t";
    }
    cout << endl;
}

void neural_network::set_in_min_max(double a, double b){
    input_minimums.push_back(a);
    input_maximums.push_back(b);
    assert(input_minimums.size() < input.layer_nodes.size()); // less than because bias.
}

void neural_network::set_out_min_max(double a, double b){
    output_minimums.push_back(a);
    output_maximums.push_back(b);
    assert(output_minimums.size() <= output.layer_nodes.size());
}
void neural_network::display_out_min_max(int output_node){
    cout << output_minimums.at(output_node) << "\t" << output_maximums.at(output_node) << endl;
}

void neural_network::set_vector_input(vector<double> a){
    input_values.clear();
    input_values = a;
}

double neural_network::get_output(int spot){
    return recorded_outputs.at(spot);
}

void layer::clean(){
    for(int i=0; i<layer_nodes.size(); i++){
        layer_nodes.at(i).clean();
    }
}

void neural_network::clean(){
    input_values.clear();
    output_values.clear();
    input.clean();
    hidden.clean();
    output.clean();
}

void node::sigmoid(){
    static map< int, double > sig_iomap;
    int input_int = inp*TRIG_GRANULARITY;
    if(sig_iomap.count(input_int) == 1)
    {outp = sig_iomap.find(input_int)->second;}
    else{
        outp = 1/(1+exp(-inp));
        sig_iomap.insert(pair <int,double> (input_int,outp));
    }
}

void node::true_sigmoid(){
    outp = 1/(1+exp(-inp));
}

void neural_network::setup(int inp, int hid, int outp){
    /// clean up for initials.
    input.layer_nodes.clear();
    hidden.layer_nodes.clear();
    output.layer_nodes.clear();
    
    for(int i=0; i<=inp; i++){
        node N;
        N.clean();
        N.bias=false;
        N.make_full_connected(hid); /// no need to connect to Hidden Bias unit.
        if(i==inp){N.bias=true;}
        input.layer_nodes.push_back(N);
    }
    for(int h=0; h<=hid; h++){
        node N;
        N.clean();
        N.bias=false;
        N.make_full_connected(outp);
        if(h==hid){N.bias=true;}
        hidden.layer_nodes.push_back(N);
    }
    for(int o=0; o<outp; o++){
        node N;
        N.clean();
        output.layer_nodes.push_back(N);
    }
    
    int IH = (input.layer_nodes.size()) * (hidden.layer_nodes.size()-1); /// no need to connect to hidden bias
    int HO = (hidden.layer_nodes.size()) * output.layer_nodes.size();
    intended_size = IH + HO;
}

void neural_network::execute(){
    int input_number=input.layer_nodes.size();
    int hidden_number=hidden.layer_nodes.size();
    int output_number=output.layer_nodes.size();
    
    for(int i=0; i<input_number; i++){
        if(i<input_number-1){
            input.layer_nodes.at(i).inp = (input_values.at(i)-input_minimums.at(i))/(input_maximums.at(i)-input_minimums.at(i));
        }
        input.layer_nodes.at(i).sigmoid();
        //cout << "INPUT LAYER: " << input.layer_nodes.at(i).outp<< endl;
    }
    input.layer_nodes.back().outp=1;
    
    /// input to hidden;
    for(int i=0; i<input_number; i++){
        for(int j=0; j<input.layer_nodes.at(i).outconnections.size(); j++){
            /// value to get output
            double value = input.layer_nodes.at(i).outweights.at(j)*input.layer_nodes.at(i).outp;
            /// spot to put outp to
            int to = input.layer_nodes.at(i).outconnections.at(j);
            /// execute it.
            hidden.layer_nodes.at(to).inp+=value;
        }
    }
    
    for(int h=0; h<hidden_number; h++){
        hidden.layer_nodes.at(h).sigmoid();
        //cout << "H LAYER: " << hidden.layer_nodes.at(h).outp<< endl;
    }
    hidden.layer_nodes.back().outp=1;
    
    /// hidden to output;
    for(int h=0; h<hidden_number; h++){
        for(int j=0; j<hidden.layer_nodes.at(h).outconnections.size(); j++){
            double value = hidden.layer_nodes.at(h).outweights.at(j)*hidden.layer_nodes.at(h).outp;
            int to = hidden.layer_nodes.at(h).outconnections.at(j);
            //cout << "HIDDEN VALUE: " << value << "\t TO " << to << endl;
            output.layer_nodes.at(to).inp+=value;
        }
    }
    
    /// output nodes to output values;
    output_values.clear();
    for(int o=0; o<output_number; o++){
        output.layer_nodes.at(o).sigmoid();
        //cout << "O LAYER: " << o << "::" << output.layer_nodes.at(o).outp << endl;
        output.layer_nodes.at(o).output_floor();
        //cout << "O LAYERfloor: " << o << "::" << output.layer_nodes.at(o).outp<< endl;
        output.layer_nodes.at(o).output_ceiling();
        //cout << "O LAYERceil: " << o << "::" << output.layer_nodes.at(o).outp<< endl;
        output_values.push_back(output.layer_nodes.at(o).outp*(output_maximums.at(o)-output_minimums.at(o))+output_minimums.at(o));
        //cout << "O LAYERout: " << output.layer_nodes.at(o).outp*(output_maximums.at(o)-output_minimums.at(o))+output_minimums.at(o) << endl;
    }
    recorded_outputs = output_values;
    clean();
}

void node::output_floor(){
    if(outp<0.01){
        outp=0;
    }
}
void node::output_ceiling(){
    if(outp>0.99){
        outp=1;
    }
}

#endif /* LY_NN_h */
