// <!-- Add this script at the end of your HTML document -->

  document.addEventListener("DOMContentLoaded", function () {
    const inputField = document.querySelector(".form-control");
    const sendButton = document.querySelector(".send-icon");

    sendButton.addEventListener("click", function () {
      const message = inputField.value.trim();
      if (message !== "") {
        // Create a new outgoing message element
        const outgoingChats = document.querySelector(".outgoing-chats");
        const outgoingMsg = document.createElement("div");
        outgoingMsg.className = "outgoing-chats";
        outgoingMsg.innerHTML = `
          <div class="outgoing-chats-img">
            <img src="ram.jpg" />
          </div>
          <div class="outgoing-msg">
            <div class="outgoing-chats-msg">
              <p>${message}</p>
              <span class="time">${getCurrentTime()}</span>
            </div>
          </div>
        `;

        // Append the new outgoing message to the chat container
        const msgPage = document.querySelector(".msg-page");
        msgPage.appendChild(outgoingMsg);

        // Clear the input field
        inputField.value = "";
      }
    });

    function getCurrentTime() {
      const now = new Date();
      const hours = now.getHours().toString().padStart(2, "0");
      const minutes = now.getMinutes().toString().padStart(2, "0");
      return `${hours}:${minutes} AM | ${now.toDateString()}`;
    }
  });
