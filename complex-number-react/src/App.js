
import './App.css';
import React, {Component} from "react";

class App extends Component {
    state = {
        real1: "",
        img1: "",
        real2:"",
        img2:"",
        result:""
      };

    
      onReal1Change = e => {
        this.setState({
          real1: e.target.value
        });
      };
    
      onImg1Change = e => {
        this.setState({
          img1: e.target.value
        });
      };

      onReal2Change = e => {
        this.setState({
          real2: e.target.value
        });
      };

      onImg2Change = e => {
        this.setState({
          img2: e.target.value
        });
      };

      postRequestSetter = () => {
        return(  {
          method: 'POST',
          headers: { 'Content-Type': 'application/json' },
          body:JSON.stringify( {
              "real1": this.state.real1,
              "img1": this.state.img1,
              "real2": this.state.real2,
              "img2": this.state.img2
          }) 
          
      });
      }

      handleAdd = e => {
          console.log("Inside HandleAdd");
        e.preventDefault();
        var requestOptions = this.postRequestSetter();
        fetch("http://localhost:3003/add",requestOptions)
          .then(async res => {const data = await res.json(); this.setState({result:data.addoutput})})
          .catch(err => console.log(err,"hello"));
      };

      handleSub = e => {
        console.log("Inside HandleSub");
      e.preventDefault();
      var requestOptions = this.postRequestSetter();
      fetch("http://localhost:3003/sub",requestOptions)
        .then(async res => {const data = await res.json(); this.setState({result:data.suboutput})})
        .catch(err => console.log(err,"hello"));
    };

    handleMul = e => {
      console.log("Inside HandleMul");
    e.preventDefault();
    var requestOptions = this.postRequestSetter();
    fetch("http://localhost:3003/mul",requestOptions)
      .then(async res => {const data = await res.json();  this.setState({result:data.muloutput})})
      .catch(err => console.log(err,"hello"));
  };

  handleDiv = e => {
    console.log("Inside HandleDiv");
  e.preventDefault();
  var requestOptions = this.postRequestSetter();
  fetch("http://localhost:3003/div",requestOptions)
    .then(async res => {const data = await res.json();  this.setState({result:data.divoutput})})
    .catch(err => console.log(err,"hello"));
};
    
render(){
  return (
    <div>
    <form className="POST">
    <div id="card" className="POST">
            <div className="formBox">
                <label>Complex no 1 real:  
                <input type="text" id="real1" name="real1" value={this.state.real1} onChange={this.onReal1Change}/></label>
                 <label>Complex no 1 img: 
                <input type="text" id="img1" name="img1" value={this.state.img1} onChange={this.onImg1Change}/></label>
            </div>
            <div id="formBox">
                <label>Complex no 2 real: 
            <input type="text" id="real2" name="real2" value={this.state.real2} onChange={this.onReal2Change}/></label>
            <label>Complex no 2 img:
                <input type="text" id="img2" name="img2" value={this.state.img2} onChange={this.onImg2Change}/></label>
            </div>

        </div>
        <br></br>
        <button type="submit" onClick={this.handleAdd}>addition</button>
        <button type="submit" onClick={this.handleSub}>subtraction</button>
        <button type="submit" onClick={this.handleMul}>multiplication</button>
        <button type="submit" onClick={this.handleDiv}>division</button>
        </form>
        <div><p>{this.state.result}</p></div>
        </div>
  );

}
}

export default App;
