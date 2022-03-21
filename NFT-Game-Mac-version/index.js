// // Source code to interact with smart contract

// // web3 provider with fallback for old version
// window.addEventListener('load', async () => {
//     // New web3 provider
//     if (window.ethereum) {
//         window.web3 = new Web3(ethereum);
//         try {
//             // ask user for permission
//             await ethereum.enable();
//             // user approved permission
//         } catch (error) {
//             // user rejected permission
//             console.log('user rejected permission');
//         }
//     }
//     // Old web3 provider
//     else if (window.web3) {
//         window.web3 = new Web3(web3.currentProvider);
//         // no need to ask for permission
//     }
//     // No web3 provider
//     else {
//         console.log('No web3 provider detected');
//     }
//   });
//   console.log (window.web3.currentProvider)
  
//   // contractAddress and abi are setted after contract deploy
//   var contractAddress = '0xc864D0fef177A69aFa8E302A1b90e450910A4c3E';
//   var abi = JSON.parse( '[{"constant":true,"inputs":[],"name":"getInfo","outputs":[{"name":"","type":"string"}],"payable":false,"stateMutability":"view","type":"function"},{"constant":false,"inputs":[{"name":"_info","type":"string"}],"name":"setInfo","outputs":[],"payable":false,"stateMutability":"nonpayable","type":"function"}]' );
  
//   //contract instance
//   contract = new web3.eth.Contract(abi, contractAddress);
  
//   // Accounts
//   var account;
  
//   web3.eth.getAccounts(function(err, accounts) {
//     if (err != null) {
//       alert("Error retrieving accounts.");
//       return;
//     }
//     if (accounts.length == 0) {
//       alert("No account found! Make sure the Ethereum client is configured properly.");
//       return;
//     }
//     account = accounts[0];
//     console.log('Account: ' + account);
//     web3.eth.defaultAccount = account;
//   });
  
//   //Smart contract functions
//   function registerSetInfo() {
//     info = $("#newInfo").val();
//     contract.methods.setInfo (info).send( {from: account}).then( function(tx) {
//       console.log("Transaction: ", tx);
//     });
//     $("#newInfo").val('');
//   }
  
//   function registerGetInfo() {
//     contract.methods.getInfo().call().then( function( info ) {
//       console.log("info: ", info);
//       document.getElementById('lastInfo').innerHTML = info;
//     });
  
//   }

//import { ethers } from "ethers";

const CONTRACT_ADDRESS = "0X1234567891233455"
const connectWallet = async () => {
  try {
    const { ethereum } = window;

    if (!ethereum) {
      alert("Get MetaMask!");
      return;
    }

    const accounts = await ethereum.request({ method: "eth_requestAccounts" });

    console.log("Connected", accounts[0]);

  } catch (error) {
    console.log(error)
  }
}

const mintNFT = async () => {
  try {
    const { ethereum } = window;

    if (ethereum) {
      // const provider = new ethers.providers.Web3Provider(ethereum);
      // const signer = provider.getSigner();
      // const connectedContract = new ethers.Contract(CONTRACT_ADDRESS, myEpicNft.abi, signer);
      const connectedContract = new web3.eth.Contract(abi, CONTRACT_ADDRESS);

      console.log("Going to pop wallet now to pay gas...")
      let nftTxn = await connectedContract.mintNFT();

      console.log("Mining...please wait.")
      await nftTxn.wait();
      
      // console.log(`Mined, see transaction: https://rinkeby.etherscan.io/tx/${nftTxn.hash}`);
      // let getMints = await connectedContract.getTotalMints();
      // setMints(getMints.toNumber());

    } else {
      console.log("Ethereum object doesn't exist!");
    }
  } catch (error) {
    console.log(error)
  }
}